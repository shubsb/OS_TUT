#define _XOPEN_SOURCE 700 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int moving_sum[5];
sem_t a;

struct value {
  int index;
  int number;
};

void factorial (void* vals){
  int sum = 1;

  struct value* val = vals;

  int index = val->index;
  int number = val->number

  for (int i = 2; i <= number; i++) {
    sum *= i;
  }

  sem_wait(& a);

  int s_val;

  sem_getvalue(& a, & s_val);

  if(index > 0) {
    sum += moving_sum[index - 1];
    moving_sum[index] = sum;

    while(moving_sum[index] <= 0) {
      sem_post(& a);
    }
  }

  sem_post(& a);
}


int main(void){
  pthread_t t1[5];

  struct value val;

  for (int i = 0; i<5; i++) {
    moving_sum[i] = 0;
  }

  sem_init(& a, 0, 1);

  for (int i =0; i<5; i++) {
    printf("%s\n","Enter a number:");

    val.index = i;

    scanf("%d", & val.number);

    pthread_create(& t1[i], NULL, factorial, & val);
    pthread_join(t1[i], NULL);
  }

  for(int i = 0; i < 5; ++i) {
    printf("Moving Sum: %d\n", moving_sum[i]);
  }

  sem_destroy(& a);
}
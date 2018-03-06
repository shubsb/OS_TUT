#define _XOPEN_SOURCE 700 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int total = 0;
int count = 5;

sem_t s;

void factorial (void* vals) {

  int sum = 1;
  int* val = vals;

  for (int i = 1; i <= *val; i++) {
    sum *= i;
  }

  sem_wait(& s);

  total += sum;

  printf("Calculated Factorial: %d, Current Factorial: %d\n", total, sum);

  sem_post(&s);
}


int main(void) {
  pthread_t t1[count];

  pid_t child;

  FILE* file = fopen("numbers.txt", "w");

  for (int i = 0; i < count; i++) {
    int val;
    printf("%s\n","Enter number");
    scanf("%d", & val);
    fprintf(file, "%d\n", val);
  }

  fclose(file);

  child = fork();

  printf("%d\n", child);

  if (child == 0) {

      sem_init(&s, 0, 1);

      file = fopen("numbers.txt", "r");

      int val[count];

      for(int i = 0; i < count; i++) {
        fscanf(file,"%d", & val[i]);
        pthread_create(&t1[i], NULL, & factorial, & val[i]);
        pthread_join(t1[i], NULL);
      }

      fclose(file);

      sem_destroy(&s);

      file= fopen("sum.txt", "w");
      fprintf(file, "%d", total);
      fclose(file);
  }

  file = fopen("sum.txt", "r");

  int out;

  fscanf(file, "%d", & out);
  printf("Total: %d\n", out);

  fclose(file);
}
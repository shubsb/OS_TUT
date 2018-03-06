#define _XOPEN_SOURCE 700 // required for barriers to work
#define NUMBERS 10
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t s;

int len_of_buffer = 5;
int buffer[5] = {0};

void producer(void* val) {

  int count = 0;

  int* value = val;

  while(count < NUMBERS) {

    sem_wait(& s);

    if(len_of_buffer < 5) {

      buffer[len_of_buffer] = value[count];

      printf("Produced %d\n", buffer[len_of_buffer]);

      len_of_buffer++;

      count++;
    }

    sem_post(&s);
  }
}

void consumer(){

  int count = 0;

  while(count < NUMBERS) {

    sem_wait(&s);

    if(len_of_buffer > 0) {

      printf("Consumed %d\n", buffer[len_of_buffer - 1]);

      buffer[len_of_buffer] = 0;

      len_of_buffer--;

      count++;

      int sleep_len = rand() % 2;

      sleep(sleep_len) ;
    }
    sem_post(&s);
  }
}

int main(void){
  pthread_t c;
  pthread_t p;

  int value[NUMBERS];

  for (int i =0; i<NUMBERS; i++) {
      printf("%s\n", "Enter a number:");
      scanf("%d", & value[i]);
    }

    len_of_buffer = 0;

    sem_init(& s, 0, 1);

    pthread_create(& p, NULL, &producer, value);
    pthread_create(& c, NULL, &consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    sem_destroy(&s);
}
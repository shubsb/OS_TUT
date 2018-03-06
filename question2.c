#define _XOPEN_SOURCE 700 // required for barriers to work
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int main(void)
{
  pid_t child;
  int status = 0;
  child = fork();
  if (child == 0) {
    sleep(1);
    printf("Parent process\n");
    wait(&status);
    if (status == 0) {
      printf("Child process terminated!\n");
    }
  } else {
    printf("Child process\n");
  }
  return 0;
}

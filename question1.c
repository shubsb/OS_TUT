#define _XOPEN_SOURCE 700 // required for barriers to work
#define FILE1 "child1.txt"
#define FILE2 "child2.txt"
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

int main(void)
{
  FILE * file1 = fopen(FILE1, "w");
  FILE * file2 = fopen(FILE2, "w");
  FILE * Rfile1 = fopen(FILE1, "r");
  FILE * Rfile2 = fopen(FILE2, "r");

  pid_t child_A, child_B;

  child_A = fork(); // Cannot figure out why it's giving waring for implicit declaration

  if(child_A == 0){ // Child A
    sleep(1); // Cannot figure out why it's giving waring for implicit declaration

    // writes to the file
    fprintf(file1, "Child 1\n");
    fclose(file1);

    // reads from the file
    int childA;
    if (Rfile1) {
      while ((childA = getc(Rfile1)) != EOF)
      putchar(childA);
      fclose(Rfile1);
     }
    } 

    else if(child_A > 0){ // Child B
    sleep(1); // Cannot figure out why it's giving waring for implicit declaration

    child_B = fork();// Cannot figure out why it's giving waring for implicit declaration
    if(child_B == 0){
      // Writes to the file
      fprintf(file2, "Child 2\n");
      fclose(file2);

      // reads from the file
      int childB;
      if (Rfile2) {
        while((childB = getc(Rfile2)) != EOF)
        putchar(childB);
        fclose(Rfile2);
      }
    }
  }
  return 0;
}

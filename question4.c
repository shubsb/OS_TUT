#include <stdlib.h>
#include <stdio.h>
#include <string.h>
 
int main (void) {

   char *professor = NULL;
   int *student_ids = NULL;
   int *grades = NULL;

   int num_of_students;

   professor = (char *) calloc(256, sizeof(char)); 

   printf("What is the name of the professor: ");
   scanf("%s", professor);

   printf("Number of students to mark: ");
   scanf("%d", &num_of_students);

   student_ids = (int *) malloc(sizeof(int) * num_of_students); 
   grades = (int *) malloc(sizeof(int) * num_of_students); 

   free(professor), free(student_ids), free(grades);

   return 0;
}


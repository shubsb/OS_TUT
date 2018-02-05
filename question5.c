#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct grade {
   int student_id;
   int mark;
};

void grade_students(struct grade *grades, int num_students);
 
int main (void) {

   char *professor = NULL;
   struct grade *grades;

   int num_students;

   professor = (char *) calloc(256, sizeof(char)); 

   printf("What is the name of the professor: ");
   scanf("%s", professor);
   printf("Number of students to mark: ");
   scanf("%d", &num_students);

   grades = malloc(sizeof(*grades) * num_students); 

   for(int i = 0; i < num_students; i++) {  
        printf("StudentID: ");
        scanf("%d", &grades[i].student_id);
        printf("Mark: ");
        scanf("%d", &grades[i].mark);            
   }

   grade_students(grades, num_students);

   free(professor), free(grades);

   return 0;
}

void grade_students(struct grade *grades, int num_students) {
   FILE *file = fopen("grades.txt", "w");

   int sum = 0; 
   int sum_of_squares = 0;

   for(int i = 0; i < num_students; i++) {
   	fprintf(file, "Student ID: %d, Mark: %d\n", grades[i].student_id, grades[i].mark);
        sum += grades[i].mark;
   }

   int avg_mark = sum/num_students;
   
   for(int i = 0; i < num_students; i++) {
        sum_of_squares += pow((grades[i].mark - avg_mark),2);
   }

   int std_dev = sqrt(sum_of_squares/(num_students-1));

   fprintf(file, "Average: %d SD: %d \n", avg_mark, std_dev);

   fclose(file);
}


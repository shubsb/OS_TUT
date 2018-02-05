#include <stdlib.h>
#include <stdio.h>

struct student {
   int student_id;
   int age;
   int start_year;
};

void save_student(struct student students);
 
int main (void) {

   struct student Student1;

   printf("Student ID: \n");
   scanf("%d", &Student1.student_id);
   printf("Age: \n");
   scanf("%d", &Student1.age);
   printf("Year started at UOIT: \n");
   scanf("%d", &Student1.start_year);

   save_student(Student1);

   return 0;
}

void save_student(struct student students) {
   FILE *file = fopen("students.txt", "a");
   fprintf(file, "%d,%d,%d \n", students.student_id, students.age, students.start_year);
   fclose(file);
}
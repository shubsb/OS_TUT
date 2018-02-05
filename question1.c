#include <stdlib.h>
#include <stdio.h>
 
int main (void) {

   int age; 
   float height;
   char name[256]; 

   printf("Enter your name: ");
   scanf("%s", &name[0]);
   printf("Enter your age: ");
   scanf("%d", &age);
   printf("Enter your height(meters): ");
   scanf("%f", &height);

   printf("Name: %s \n", name);
   printf("Age: %d \n", age);
   printf("Height: %.2f m \n", height);

   return 0;
}
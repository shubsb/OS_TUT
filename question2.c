#include <stdlib.h>
#include <stdio.h>
 
int main (void) {

   FILE* file = fopen("question2.txt", "r");
   int n;
   int i = 0;
   int num[10]; 

   while(fscanf(file, "%d", &n) > 0) 
   {
   	num[i] = n;
        i++;
   }

   fclose(file);
   
   for(int i = 0; i < 10; i++)
   {
   	printf("%d \n", num[i]);
   }

   return 0;
}
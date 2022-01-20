#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
   int x,i;
   int *p;
   printf("Enter the size of 1-D array : \n");
   scanf("%d",&x);
   p =(int *)malloc(x*sizeof(int));
   if(p==NULL)
   {
      printf("Memory not allocated.");
      exit(1);
   }
   else
   {
      printf("Memory has been allocated.\n");
      printf("Please enter elements one by one.\n");
      for(i=0;i<x;i++)
      {
        scanf("%d",(p+i));
      }
   } 
   printf("\nEntered elements are : \n");
   for(i=0;i<x;i++)
   {
      printf("%d\n",*(p+i));
   }
   return 0;
}


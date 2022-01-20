#include<stdio.h>
int main()
{
   int x;
   int *p;
   int **pp;

   printf("Enter the value of integer : \n");
   scanf("%d",&x);
   p=&x;
   pp=&p;
   
   printf("Value of %d using variable is : %d\n",x,x);
   printf("Vlaue of %d using pointer pointing to variable is : %d\n",x,*p);
   printf("Vlaue of %d using pointer , pointing to pointer is : %d\n",x,**pp);
   return 0;
} 


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  int arr[100][100],i,j,r,c;
  int *p[100][100];
  printf("Enter the number of rows in the array : \n");
  scanf("%d",&r);
  printf("Enter the number of columns in the array : \n");
  scanf("%d",&c);
  printf("Enter the elements one by one : \n");
  for(i=1;i<=r;i++)
  {
    for(j=1;j<=c;j++)
    {
       printf("Enter a[%d][%d] = \t",i,j);
       scanf("%d",&arr[i][j]);
    }
  }
  for(i=1;i<=r;i++)
  {
    for(j=1;j<=c;j++)
    {
       p[i][j]=&arr[i][j];
    }
  }
 
  printf("Printing array using pointers : \n");
  for(i=1;i<=r;i++)
  {
    for(j=1;j<=c;j++)
    {
       printf("%d\t",*(p[i][j]));
    }
    printf("\n");
  }
  return 0;
} 
  


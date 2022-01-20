#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
  int arr[50][50],n,i,j,r,c;
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
  int (*p)[50] = arr;
  printf("\nPrinting the entered array using pointer to an array : \n");
  for(i=1;i<=r;i++)
  {  
    for(j=1;j<=c;j++)
    {
       printf("%d  ",*(p[i]+j));
    }
    printf("\n");
  }
  return 0;
}  

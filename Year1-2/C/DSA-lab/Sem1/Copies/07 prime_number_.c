#include<stdio.h>
int main()
{
  int i,j,upper=1000000000,lower=10000000,n,rem[40],arr[10];
  int p[]= {1031,1013,1223,1249};
  FILE *fp;
  fp = fopen("prime_numbers.txt","w");
  for(i=0;i<4;i++)
  {
  	fprintf(fp,"%d\n",p[i]);
  }
  srand();
  for(i=0;i<10;i++)
  {
    n=(rand()%(upper-lower+1)+lower);
    arr[i]=n;
  }
  printf("Random number are :\n");
  for(i=0;i<10;i++)
  {
    printf("%d - %d \n",i+1,arr[i]);
  }
  for(j=0;j<4;j++)
  {
    printf("\n\nprime number =%d \n",p[j]);
    printf("      L(i)'s               R(i)'s          \n");
    for(i=0;i<10;i++)
    {
  
    rem[i]=arr[i]%p[j];
    printf("      %d      =       %d       \n",arr[i],rem[i]);

      }  
  }
}

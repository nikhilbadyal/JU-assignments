#include<stdio.h>
int main()
{    
	int i,j,p[4],upper=10000000,lower=1000000,n,rem[40],arr[10];
	p[0]=1031;
	p[1]=1013;
	p[2]=1223;
	p[3]=1249;
	p[4]=1447;
	p[5]=1699;
	p[6]=1709;
	srand();
	for(i=0;i<10;i++)  //taking 10 large numbers
	{
		n=(rand()%(upper-lower+1)+lower);
		arr[i]=n;
	}
	printf("Random number are :\n");
	for(i=0;i<10;i++)
	{
		printf("%d - %d \n",i+1,arr[i]);
	}
	for(j=0;j<7;j++)
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

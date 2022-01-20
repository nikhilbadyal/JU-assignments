#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int print_values(int *p,int n)
{
	int i;
	printf("\nEntered array is :\n");
	for(i=0;i<n;i++)
	{
		printf(" %d ",*(p+i));
	}
	return 0;
}

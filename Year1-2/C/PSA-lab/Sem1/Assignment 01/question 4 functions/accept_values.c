#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int* accept_values(int *p,int n)
{
	int i;
	printf("\nEnter the elements of array one by one:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",(p+i));
	}
	printf("\nArray sucessfully created.\n");
	return p;
}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int* allocate_memory(int n)
{
	int *p = (int *)malloc(n*sizeof(int));
	if(p==NULL)
	{
		printf("\nOOPS ! Memory not allocated.\n");
		return 0;
	}
	else
	{
		printf("\nMemory succesfully alloctaed.\n");
		//printf("%d",p);
		return p;
	}
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int* allocate_memory(int *pdim)
{
	int r=*pdim,c=*(pdim+1);
    printf("%d  %d",r,c);
	int i;
	int *arr = (int *)malloc(r*c*sizeof(int));
	if(arr==NULL)
	{
		printf("\nMemory not allocated allocated.\n");
		
	}
	else
	{
		printf("\nMemory sucessfully allocated.");
		return arr;
	}	
}

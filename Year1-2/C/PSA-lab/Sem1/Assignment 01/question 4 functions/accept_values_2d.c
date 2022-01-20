#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int* accept_values(int *arr,int* pdim)
{
	int i,j;
    int r=*pdim,c=*(pdim+1);
    printf("\n%d  %d",r,c);
	printf("\nEnter the elements one by one : \n");
	for (i = 0; i < r; i++) 
	for (j = 0; j < c; j++) 
	{
		scanf("%d",(arr + i*c + j));
	}
	printf("\nArray sucessfully created.\n");
	printf("Sucess");
	return arr;
}

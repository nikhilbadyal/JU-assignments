#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int print_values(int *arr,int* pdim)
{
	int i,j;
	int r=*pdim,c=*(pdim+1);
	printf("Entered array is : \n");
	for (i = 0; i < r; i++) 
	for (j = 0; j < c; j++) 
		printf("%d ", *(arr + i*c + j)); 
	printf("\nSucess\n"); 
	return 0;
}

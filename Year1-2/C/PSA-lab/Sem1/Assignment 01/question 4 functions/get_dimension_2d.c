#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int* get_dim()
{
	int i;
	int *pdim = (int *)malloc(2*sizeof(int));
	printf("Enter the no. of rows and column you want in array :\n");
	for(i=0;i<2;i++)
    {
        scanf("%d",(pdim+i));
    }
	printf("Dimensions inputed.\n");
	return pdim;
}

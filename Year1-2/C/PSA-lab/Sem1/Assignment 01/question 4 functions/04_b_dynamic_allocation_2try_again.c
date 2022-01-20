#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int* get_dim()
{
	int dim[2];
	printf("Enter the no. of rows and column you want in array :\n");
	scanf("%d%d",&dim[0],&dim[1]);
	int *pdim = dim;
	printf("Dimensions inputed.\n");
	return pdim;
}
int* allocate_memory(int *pdim)
{
	int r=*pdim,c=*(pdim+1);
//	printf("%d%d",r,c);
    //int r=3,c=3,
	int i;
	int *arr[r];
//	int *arr = (int *)malloc(r*sizeof(int));
	for(i=0;i<r;i++)
	{
		arr[i] = (int *)malloc(c*sizeof(int));
	}
	if(arr==NULL)
	{
		printf("\nMemory not allocated allocated.\n");
		
	}
	else
	{
		printf("Memory sucessfully allocated.");
		return arr;
	}	
}
int* accept_values(int *arr,int*pdim)
{
	int i,j;
    int r=*pdim,c=*(pdim+1);
 //   printf("%d%d",r,c);
	printf("\nEnter the elements one by one : \n");
	for(i=0;i<r;r++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}
	printf("\nArray sucessfully created.\n");
	printf("Sucess");
	return arr;
}
int print_values(int *arr,int*pdim)
{
	int i,j;
	int r=*pdim,c=*(pdim+1);
	printf("Entered array is : \n");
	for(i=0;i<r;r++)
	{
		for(j=0;j<c;j++)
		{
			printf(" %d ",arr[i][j]);
		}
	}
	printf("Sucess"); 
	return 0;
}
int main()
{
	int *n= get_dim();
	int *p = allocate_memory(n);
	int *p1 = accept_values(p,n);
	int r = print_values(p1,n);
	return 0;
}

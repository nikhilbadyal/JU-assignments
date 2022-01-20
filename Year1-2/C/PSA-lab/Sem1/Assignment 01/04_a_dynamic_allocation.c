#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int get_dim()
{
	int n;
	printf("Enter the no. of elements you want in the array:\n");
	scanf("%d",&n);
	return n;
}
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
int* accept_values(int *p,int n)
{
	int i;
	printf("\nEnter the elements of array one by one:\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",(p+i));
	}
	printf("\nArray successfully created.\n");
	return p;
}
void print_values(int *p,int n)
{
	int i;
	printf("\nEntered array is :\n");
	for(i=0;i<n;i++)
	{
		printf(" %d ",*(p+i));
	}
}
int main()
{
	int n =get_dim();
	int *p = allocate_memory(n);
	int *p1 = accept_values(p,n);
	print_values(p1,n);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
int arr[2];

int *get_dim()
{
	int r,c;
	printf("Enter number of rows and columns:\n");
	scanf("%d%d",&r,&c);
	arr[0]=r;
	arr[1]=c;
	return(arr);
}


int **allocate_memory(int r,int c)
{
	int i;
	int **ptr;
	
    ptr=(int **)malloc(r*sizeof(int *));
	for(i=0;i<r;i++)
	{
		ptr[i]=(int  *)malloc(c*sizeof(int));
	}
	
	return(ptr);
}


int **accept_values(int **allocate,int r,int c)
{
	int i,j;
	printf("Enter the elements of array :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&allocate[i][j]);
		}
	}
	return(allocate);
}

void print_values(int **accept,int r,int c)
{

	int i,j;
	printf("\nEntered values of array are :\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",accept[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int *dim,**allocate,r,c,**accept;
	dim=get_dim();
	r=*dim;
	c=*(dim+1);
    allocate=allocate_memory(r,c);
    if(allocate==NULL)
    {
    	printf("ERROR: Memory cannot be allocated \n");
	}
	else
	{
		printf("Memory allocated\n");
	}
	accept=accept_values(allocate,r,c);
	print_values(accept,r,c);
}

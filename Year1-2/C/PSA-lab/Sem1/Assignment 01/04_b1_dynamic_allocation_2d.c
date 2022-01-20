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
int* allocate_memory(int *pdim)
{
	int r=*pdim,c=*(pdim+1);
 //   printf("%d  %d",r,c);
	int i;
	int *arr = (int *)malloc(r*c*sizeof(int));
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
int* accept_values(int *arr,int* pdim)
{
	int i,j;
    int r=*pdim,c=*(pdim+1);
//    printf("\n%d  %d",r,c);
	printf("\nEnter the elements one by one : \n");
	for (i = 0; i < r; i++)
    {
        for (j = 0; j < c; j++)
        {
            scanf("%d",(arr + i*c + j));
        }
    }

	printf("\nArray sucessfully created.\n");
//	printf("Sucess\n");
	return arr;
}
int print_values(int *arr,int* pdim)
{
	int i,j;
	int r=*pdim,c=*(pdim+1);
	printf("\nEntered array is : \n");
	for (i = 0; i < r; i++)
	{
		for (j = 0; j < c; j++)
		{
			printf("%d   ", *(arr + i*c + j));
		}
		printf("\n");

	}

//	printf("\nSucess\n");
	return 0;
}
int main()
{
	system("cls");
    system("color 9");
	int *n= get_dim();
	int *p = allocate_memory(n);
	int *p1 = accept_values(p,n);
	int r = print_values(p1,n);
	return 0;
}

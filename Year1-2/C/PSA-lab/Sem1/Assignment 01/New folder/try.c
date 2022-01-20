#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *c;
int *r;
int get_dim()
{
	
	int i,r_global,c_global;
	int *pdim = (int *)malloc(2*sizeof(int));
	printf("Enter the no. of rows and column you want in array :\n");
    scanf("%d%d",r_global,c_global);
    int *r = (int *)malloc(r_global*sizeof(int));
    int *c = (int *)malloc(c_global*sizeof(int));
	printf("Dimensions inputed.\n");
	return 0;
}
#define SIZE_OF_ARRAY (15)
typedef int *(*p_array_t)[SIZE_OF_ARRAY];
p_array_t allocate_memory()
{ 
    
	//int r=*pdim,c=*(pdim+1);
	
 //   printf("%d  %d",r,c);
	int i;
	
	int *(*function(int *arg))[15]; 

	int *arr[14];
	for(i=0;i<(*r);i++)
	{
		arr[i]= (int *)malloc(*c*sizeof(int));
	}
//	int *arr = (int *)malloc(r*c*sizeof(int));
    
	if(arr==NULL)
	{
		printf("\nMemory not allocated allocated.\n");
		
	}
	else
	{
		printf("Memory sucessfully allocated.");
		p_array_t ret = &arr;
		return ret;
	}	
}
int* accept_values(int *(*function(int *arg))[15]; )
{
	int i,j;
   // int r=*pdim,c=*(pdim+1);
//    printf("\n%d  %d",r,c);
	printf("\nEnter the elements one by one : \n");
	for (i = 0; i < (*r); i++) 
	for (j = 0; j < (*c); j++) 
	{
		scanf("%d",(arr + i*(*c) + j));
	}
	printf("\nArray sucessfully created.\n");
//	printf("Sucess\n");
	return arr;
}
int print_values(int *arr)
{
	int i,j;
//	int r=*pdim,c=*(pdim+1);
	printf("\nEntered array is : \n");
	for (i = 0; i < (*r); i++)
	{
		for (j = 0; j < (*c); j++)
		{
			printf("%d   ", *(arr + i*(*c) + j));
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
    typedef int *(*p_array_t)[SIZE_OF_ARRAY];
	get_dim();
	int *(*function(int *arg))[15]  = allocate_memory();
	int *p1 = accept_values(*(*function(int *arg))[15]);
	int r = print_values(p1);
	return 0;
}

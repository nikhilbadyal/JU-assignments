#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdio.h> 
/*void swap_name(char *str1_ptr, char *str2_ptr) 
{ 
char *temp = *str1_ptr; 
*str1_ptr = *str2_ptr; 
*str2_ptr = temp; 
} \
void swap(int* a,int *b)
{
   int t;
 
   t  = *b;
   *b = *a;
   *a = t;
}
int part(int *A,char *name,int start,int end)
{
	int i;
	int pivot = A[end]; //7
	int pindex = start; //0
	for(i=start;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			swap(&A[i],&A[pindex]);
			swap_name(name[i],&name[pindex]);
			pindex++;
		}
	}
	swap(&A[pindex],&A[end]);
	swap_name(&name[pindex],&name[end]);
	return pindex;
}
void quick_sort(int *A,char **name,int start,int end)
{
	if(start<=end)
	{
		int pindex = part(A,name,start,end);
		quick_sort(A,name,start,pindex-1);
		quick_sort(A,name,pindex+1,end);
	}
	
}*/
int main()
{
	int x,i,j;
	printf("How many persons do you have : \n");
	scanf("%d",&x);
	int *A = (int *)malloc(x*sizeof(int));
	char *name[x];
	for(i=0;i<x;i++)
	{
		name[i] = (char *)malloc(20*sizeof(char));
	}
	printf("Enter person's age and name  : \n");
	
	for(i=0;i<x;i++)
	{
		scanf("%d%s",&A[i],name[i]);
	}
	for(i=0;i<x;i++)
	{
		printf("%d%s",A[i],*name[i]);
	}
	/*quick_sort(A,name,0,x-1);
	for(i=0;i<x;i++)
	{
		printf("%d%s ",A[i],name[i]);
	}
	printf("%s",name[0]);*/

	return 0;
	
}


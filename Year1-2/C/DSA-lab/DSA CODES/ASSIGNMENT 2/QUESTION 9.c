#include<stdio.h>
#include"sort_check.h"
int *merge(int *arr1,int *arr2,int m,int n)
{
	int arr[100],i,round,j,x;
	int check1,check2;
	check1=sort_check(arr1,m);
	printf("\nCheck1 : %d \n",check1);
	
	check2=sort_check(arr2,n);
	printf("\nCheck2 : %d \n",check2);
	if(check1 !=check2  ||  check1 == 0  ||  check2 ==0)
	{
		printf("CAN'T BE MERGED :");
		return;
	}

     i=0;
	j=0;
	x=0;
	if(check1 == 1)
	{
	
		
		while(i<m && j<n)
		{
			printf("\nHELLO\n");
			if(arr1[i] >= arr2[j])
			{
				arr[x]=arr2[j];
				j++;
				x++;
			}
			else
			{
				arr[x]=arr1[i];
				i++;
				x++;
			}
		}
		while(i<m)
		{
			arr[x]=arr1[i];
			i++;
			x++;
		}
		while(j<n)
		{
			arr[x]=arr2[j];
			j++;
			x++;
		}
	}
	if(check1 == -1)
	{
		
		while(i<m && j<n)
		{
			if(arr1[i] <= arr2[j])
			{
				arr[x]=arr2[j];
				printf("\narr=%d\n",arr[x]);
				j++;
				x++;
			}
			else
			{
				arr[x]=arr1[i];
				i++;
				x++;
			}
		}
		while(i<m)
		{
			arr[x]=arr1[i];
			i++;
			x++;
		}
		while(j<m)
		{
			arr[x]=arr2[j];
			j++;
			x++;
		}
	}
	printf("\nx=%d\n",x);
	for(i=0;i<x;i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\nHELLO\n");
}
int main()
{
	int arr1[]={1,3,5,7,9};
	int arr2[]={2,4,6,8,10};
	int *arr3,i,n,m,check;
/*	printf("Enter total number of elements in first array : ");
	scanf("%d",&m);
	printf("Enter first array  : \n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&arr1[i]);
	}
	
	printf("Enter total number of elements in secoond array : ");
	scanf("%d",&n);
	printf("Enter second array  : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr2[i]);
	}*/
	
    merge(arr1,arr2,5,5);
}

#include<stdio.h>
int sort_check(int *arr,int n)
{
	int res=0,i,count_a=0,count_d=0;

	for(i=0;i<n-1;i++)
	{
		if(arr[i] >= arr[i+1])
		{
			count_d++;

		}
		if(arr[i] < arr[i+1])
		{
			count_a++;
		}
    }
    
    if(i==count_a)
    {
    	res=1;
	}
	else if(i==count_d)
	{
		res=-1;
	}
	return(res);
}
int main()
{
	int arr[100],i,n,check;
	printf("Enter total number of elements : ");
	scanf("%d",&n);
	printf("Enter array  : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	check=sort_check(arr,n);
	if(check == 1)
	{
		printf("\nASCENDING ORDER  :");
	}
	else if(check == -1)
	{
		printf("\nDESCENDING ORDER : \n");
	}
	else if(check == 0)
	{
		printf("\nTHE GIVEN ARRAY IS NOT SORTED :");
	}
}

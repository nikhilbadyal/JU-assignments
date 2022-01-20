#include<stdio.h>
#include<stdlib.h>
void swap(int* a,int *b)
{
   int t;
 
   t  = *b;
   *b = *a;
   *a = t;
}
int part(int *A,int start,int end)
{
	int i;
	int pivot = A[end]; 
	int pindex = start; 
	for(i=start;i<end;i++)
	{
		if(A[i]<=pivot)
		{
			swap(&A[i],&A[pindex]);
			pindex++;
		}
	}
	swap(&A[pindex],&A[end]);
	return pindex;
}
void quick_sort(int *A,int start,int end)
{
	if(start<=end)
	{
		int pindex = part(A,start,end);
		quick_sort(A,start,pindex-1);
		quick_sort(A,pindex+1,end);
	}
	
}
int main()
{

    int x,i,n,arr[10],lower_bound,higher_bound,s,mid;

    printf("Enter the number of elements you want in array : \n");
    scanf("%d",&n);
    printf("Enter the elements of array : \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quick_sort(arr,0,n-1);
    printf("Enter the digit you want to search : \n");
    scanf("%d",&s);
    lower_bound=0;
    higher_bound=n-1;


    while(lower_bound<=higher_bound)
    {
        mid = (lower_bound+higher_bound)/2;
        if(s<arr[mid])
            higher_bound=mid-1;
        else if(arr[mid]<s)
        {
                lower_bound=mid+1;
        }
        else if(lower_bound=higher_bound)
        {
            printf("Seacrh succesfull.Element found at  %d position.",(mid+1));
            break;
        }

    }
    if(lower_bound>higher_bound)
    {
    	printf("Element is not present in the given array.",s);
	}
    return 0;
}

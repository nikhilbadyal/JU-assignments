#include<stdio.h>
#include<stdlib.h>
void swap(int * , int *);
int part(int *,int ,int );
void quick_sort(int *,int ,int );
void binarySearch(int *, int , int );
void linearSearch(int *, int , int );


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
	int pivot = A[end]; //7
	int pindex = start; //0
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
void binarySearch(int *arr, int n, int s)
{
    int lower_bound,higher_bound,mid;

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
        else if(lower_bound==higher_bound)
        {
            printf("Search successful.In sorted array element found at  %d position.\n",(mid+1));
            break;
        }

    }
    if(lower_bound>higher_bound)
    {
    	printf("Element %d is not present in array.\n",s);
	}
    return ;
}
void linearSearch(int * arr ,int n, int x )
{
    int i;
    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            printf("Search successful.In sorted array element found at  %d position.\n",(i+1));
            break;
		}

    }
    if(i==n)
    {
        printf("%d not present in array.\n",x);
    }
}
int main()
{

    int i,n,arr[10],s;

    printf("Enter the number of elements you want in array : \n");
    scanf("%d",&n);
    printf("Enter the elements of array : \n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    quick_sort(arr,0,n-1);
    printf("Enter the digit you want to search : \n");
    scanf("%d",&s);
    printf("\nResult by Binary search.\n");
    binarySearch(arr,10,s);
    printf("\nResult by Linear search.\n");
    linearSearch(arr,10,s);
}

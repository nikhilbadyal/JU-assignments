#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
# define my_sizeof(type) ((char *)(&type+1)-(char*)(&type))
void Print(int *arr , int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf(" %d",arr[i]);
    }
}
void ReversePrint(int *arr, int size)
{
    int i =size-1;
    for(i;i>=0;i--)
    {
        printf(" %d",arr[i]);
    }
}
void Insert(int *arr , int size, int value, int pos)
{
    int i = size-1;
    for(i;i>=pos;i--)
    {
        arr[i] = arr[i-1];
    }
    arr[i] = value;

    for(i=0;i<size;i++)
    {
        printf("%d  ",arr[i]);
    }
}
void delete(int *arr, int size,int pos)
{
    int i ;
     for(i=pos;i<size;i++)
     {
         arr[i-1] = arr[i];
     }
     arr[i-1] = 0;
}
void Reverse(int *arr , int size)
{
    int i ;
    for(i=0;i<(size/2);i++)
    {
        int temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}
bool equality(int *arr1, int size1, int *arr2 , int size2)
{
    if(size1!= size2){
        return 0;}
    int i;
    for(i=0;i<size1;i++)
    {
        if(arr1[i]!= arr2[i])
            return 0;
    }
    return 1;
}
bool linearSearch(int *arr, int size , int value)
{
    int i ;
    for(i=0;i<size;i++)
    {
        if(arr[i]==value)
        {
            return 1;
        	//printf("%d number is present at %d.",value,i+1);
           // break;
		}

    }
    if(i==size)
    {
        return 0;
      //  printf("%d not present in array.",value);
    }
}
bool binarySearch(int *arr , int size , int value)
{
    int lower_bound , higher_bound , mid;
    lower_bound=0;
    higher_bound=size-1;


    while(lower_bound<=higher_bound)
    {
        mid = (lower_bound+higher_bound)/2;
        if(value<arr[mid])
            higher_bound=mid-1;
        else if(arr[mid]<value)
        {
                lower_bound=mid+1;
        }
        else if(lower_bound=higher_bound)
        {
            return 1;
           // printf("Search successful.In sorted array element found at  %d position.",(mid+1));
           // break;
        }

    }
    if(lower_bound>higher_bound)
    {
        return 0;
    	//printf("Element is not present in array.",s);
	}
}
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
void merge(int *arr1 , int size1 , int *arr2 , int size2)
{
    int i  = 0 , j  =0 , k =0 ;
    int size3 = size1 + size2;
   // printf("%d",size3);
    int *arr = (int *) malloc(size3*sizeof(int));
    while(i < size1 && j < size2 )
    {
        if(arr1[i]<arr2[j]){
             //   printf("Here ");
            arr[k] = arr1[i];
            i++;
            k++;}
        else{
            arr[k] = arr2[j];
            j++;
            k++;}
    }

    while(i<size1)
    {
        arr[k] = arr1[i];
        i++;
        k++;
    }
    while(j<size2)
    {
        arr[k] = arr2[j];
        k++;
        j++;
    }
    for(i=0;i<size3;i++)
    {
        printf("%d  ",arr[i]);
    }

}
int* removeDupSort(int *arr, int n)
{
    int i;
	if (n==0 || n==1)
		return arr;

	// To store index of next unique element
	int j = 0;

	// Doing same as done in Method 1
	// Just maintaining another updated index i.e. j
	for (int i=0; i < n-1; i++)
		if (arr[i] != arr[i+1])
			arr[j++] = arr[i];

	arr[j++] = arr[n-1];


	for(i=0;i<j;i++)
    {
        printf("%d  ",arr[i]);
    }
	return arr;
}
int * removeDupUnsort(int *arr , int size)
{
    int i;
    int count = 0,c, d;
    int *b = (int* )malloc(size*sizeof(int));
    for (c = 0; c < size; c++)
    {
        for (d = 0; d < count; d++){
            if(arr[c] == b[d])
            break;}
        if (d == count){
            b[count] = arr[c];
            count++;}
    }
    for(i=0;i<count;i++)
    {
        printf("%d  ",b[i]);
    }
    return b;
}
int * removeAlt(int *arr , int size)
{
    int i , j=0;
    int *arr1 = (int *)malloc((size/2)*sizeof(int));
    for(i=0;i<size;i++)
    {
        if(i%2==0)
        {
            printf("I'm here.\n");
            arr1[j] = arr[i];
            j++;
        }
    }
    for(i=0;i<j;i++)
    {
        printf("%d  ",arr1[i]);
    }

    return arr1;
}
int * moveLtoF(int *arr , int size)
{
    int temp,i;
    temp = arr[0];
    arr[0] = arr[size-1];
    arr[size-1] = temp;

    for(i=0;i<size;i++)
    {
        printf("%d  ",arr[i]);
    }
    return arr;

}
int* swapPair(int *arr , int size)
{
    int i , temp;
    if(size%2==0)
    {
        for(i=0;i<size;i++)
        {
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            i++;
        }

    }
    if(size%2 ==1)
    {
        for(i=0;i<size-1;i++)
        {
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            i++;
            printf("%d ",i);
        }
    }
    for(i=0;i<size;i++)
    {
        printf("%d  ",arr[i]);
    }
    return arr;
}




















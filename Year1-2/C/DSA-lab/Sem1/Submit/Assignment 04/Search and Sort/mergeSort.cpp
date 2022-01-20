#include<stdio.h>
#include<math.h>
void merge_sort(int * , int);
void merge(int* , int , int * , int ,int*);
void merge(int *left , int size1, int *right , int size2,int *arr)
{
    int i,j,k;
    i = j = k= 0;
    while(i < size1 && j < size2)
    {
        if(left[i]<=right[j])
        {
            arr[k] = left[i];
            i++;
            k++;
        }
        else{
            arr[k] = right[j];
            ++k;
            ++j;
        }
    }
    while(i<size1)
    {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j<  size2)
    {
        arr[k] = right[j];
        j++;
        k++;
    }
}


void merge_sort(int *arr , int size)
{
    if(size<2) return;
    int left[20];
    int right[20];
    int i ,j ;
    int mid = size/2;
    for(i = 0 ; i <mid;++i)
    {
        left[i] = arr[i];
    }
    for( j= 0 ; j< size-mid;++j)
    {
        right[j] = arr[i];
        i++;
    }
    merge_sort(left,mid);
    merge_sort(right,(size-mid));
    merge(left,mid,right,(size-mid),arr);
}

int main()
{
    int arr[10];
	int i = 0;
	int size;
	int k = 11;
	while(k!= 1)
	{
		arr[i] = k;
		i++;
		--k;
	}
	arr[3]=193;
	arr[1]=104;
	arr[7]=300;
	for(i = 0;i<10;++i)
    {
       printf("%d ",arr[i]);
    }
    printf("\n");
	size = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,size);
    printf("Sorted.\n");
	for(i = 0;i<10;++i)
    {
       printf("%d ",arr[i]);
    }
    return 0;
}

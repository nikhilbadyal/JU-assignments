#include<stdio.h>
#include<math.h>
#define size 40

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


void merge_sort(int *arr , int n)
{
    if(n<2) return;
    int left[20];
    int right[20];
    int i ,j ;
    int mid = n/2;
    for(i = 0 ; i <mid;++i)
    {
        left[i] = arr[i];
    }
    for( j= 0 ; j< n-mid;++j)
    {
        right[j] = arr[i];
        i++;
    }
    cout<<"fine\n";
    merge_sort(left,mid);
    merge_sort(right,(n-mid));
    merge(left,mid,right,(n-mid),arr);
}

int main()
{
    int arr[size];
	int i = 0;
	int k = 40;
	for(int l = 0 ; i< 40 ; ++i)
    {
        arr[i] = ++k;
    }
	arr[3]=193;
	arr[1]=104;
	arr[7]=300;
	for(i = 0;i<size;++i)
    {
       printf("%d ",arr[i]);
    }
    printf("\n");
	//Size = sizeof(arr)/sizeof(arr[0]);
    merge_sort(arr,size);
    printf("Sorted.\n");
	for(i = 0;i<size;++i)
    {
       printf("%d ",arr[i]);
    }
    return 0;
}

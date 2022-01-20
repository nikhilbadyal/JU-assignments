#include<iostream>
void heapSort(int *  , int );
void heapify(int * , int  , int);
void swap(int * , int * );
void swap(int *x , int * y)
{
    int temp = *x;
    *x = *y;
    *y = temp;

}
void heapify(int *arr , int size  , int  i)
{
    int largest = i;
    int l = 2*i +1;
    int r = 2*i +2;

    if(l<size  && arr[l]>arr[largest])
    {
        largest = l;
    }
    if(r< size && arr[r]>arr[largest])
    {
        largest = r;
    }
    if(largest != i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,size,largest);
    }
}
void heapSort(int * arr , int size)
{

    for(int i = size/2 -1 ; i >=0 ; --i)
    {
        heapify(arr,size,i);
    }
    for(int i = size-1 ; i >=0 ; i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
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
    heapSort(arr,size);
    printf("Sorted.\n");
	for(i = 0;i<10;++i)
    {
       printf("%d ",arr[i]);
    }
    return 0;
}

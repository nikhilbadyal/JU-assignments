#include<stdio.h>
void insertion_sort(int * , int);
void insertion_sort(int *arr , int size)
{
    int i ;
    for(i = 1 ; i<size;++i)
    {
        int value = arr[i];
        int j = i-1;
        while(j >= 0&& arr[j]>value)
        {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[++j] = value;
    }
}
int main()
{
    int arr[10];
	int i = 0;
	int size;
	while(i!= 10)
	{
		arr[i] = i;
		++i;
	}
	arr[0]=100;
	arr[3]=700;
	arr[5]=164;
	arr[8]=150;
	for(i = 0;i<10;++i)
    {
        printf("%d ",arr[i]);
    }
printf("\n");
	size = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,size);
    printf("Sorted.\n");
	for(i = 0;i<10;++i)
    {
       printf("%d ",arr[i]);
    }
    return 0;
}

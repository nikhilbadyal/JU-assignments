#include<stdio.h>
void bubbleSort(int * , int  );
void swap(int* x , int *y);
void swap(int* x , int *y)
{
    int c = *x;
    *x = *y;
    *y = c;
}
void bubbleSort(int *arr , int size)
{
    int flag ;
    for(int i = 0 ; i < size-2 ; ++i)
    {
        for(int j = size-1  ; j >= i+1 ; --j)
        {
            flag = 1;
            if(arr[j]<arr[j-1])
            {
                swap(&arr[j],&arr[j-1]);
                flag = 0;
            }
        }
        if(flag) return;
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
	arr[3]=7245;
	arr[5]=164;
	arr[8]=150;
	arr[7]=125;
	arr[6]=245;
	arr[1]=945;
	for(i = 0;i<10;++i)
    {
        printf("%d ",arr[i]);
    }
	size = sizeof(arr)/sizeof(arr[0]);
	bubbleSort(arr,size);
	printf("Sorted.\n");
	for(i = 0;i<10;++i)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}

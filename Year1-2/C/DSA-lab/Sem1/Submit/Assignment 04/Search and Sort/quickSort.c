#include<stdio.h>
#include<math.h>
void quick_sort(int * , int , int );
int partition(int * , int , int );
int partition(int * arr , int start , int end)
{
    int pivot = arr[end];
    int temp;
    int pindex = start;
    for(int i = start ; i< end;++i)
    {
        if(arr[i]<=pivot)
        {
            temp = arr[pindex];
            arr[pindex] = arr[i];
            arr[i] = temp;
            pindex++;
        }
    }
    temp = arr[pindex];
    arr[pindex] = arr[end];
    arr[end] = temp;
    return pindex;
}
void quick_sort(int *arr ,int start , int end)
{
    if(start>=end) return;
    int pivot = partition(arr, start ,end);
    quick_sort(arr,start,pivot-1);
    quick_sort(arr,pivot+1,end);

}
int main()
{
    int arr[10];
	int i = 0;
	int k = 11;
	while(k!= 1)
	{
		arr[i] = k;
		i++;
		--k;
	}
	arr[3]=-3;
	arr[1]=104;
	arr[7]=300;
	for(i = 0;i<10;++i)
    {
       printf("%d ",arr[i]);
    }
    printf("\n");
    quick_sort(arr,0,9);
    printf("Sorted.\n");
	for(i = 0;i<10;++i)
    {
       printf("%d ",arr[i]);
    }
    return 0;
}

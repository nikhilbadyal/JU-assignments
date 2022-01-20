#include<stdio.h>
#include<math.h>
void heap_sort(int * , int);

void heap_sort(int * arr , int size)
{

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
	for(i = 0;i<10;++i)
    {
        printf("%d\n",arr[i]);
    }
	arr[3]=193;
	arr[1]=104;
	arr[7]=300;
	size = sizeof(arr)/sizeof(arr[0]);
    heap_sort(arr,size);
    printf("Sorted.\n");
	for(i = 0;i<10;++i)
    {
        printf("%d\n",arr[i]);
    }
    return 0;
}


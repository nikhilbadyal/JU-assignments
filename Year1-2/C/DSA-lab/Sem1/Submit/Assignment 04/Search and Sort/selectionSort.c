#include<stdio.h>

void selectionSort(int* , int );
void swap(int *, int *);
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int*arr , int size)
{
    for(int i =0 ; i <size-1;++i)
    {
        int min = i;
        for(int j= i+1; j <size;++j )
        {
            if(arr[j]<arr[min])
            {
                min = j;
               // break;c
               //swap(&arr[j],&arr[i]);
            }
        }
        swap(&arr[min],&arr[i]);
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
	arr[1]=999;
	arr[7]=300;
	for(i = 0;i<10;++i)
    {
       printf("%d  ",arr[i]);
    }
    printf("\n");
	size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,size);
    printf("Sorted.\n\n");
	for(i = 0;i<10;++i)
    {
       printf("%d  ",arr[i]);
    }
    return 0;
}

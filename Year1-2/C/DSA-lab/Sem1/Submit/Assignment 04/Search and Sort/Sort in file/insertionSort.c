#include<stdio.h>
void insertionSort(int * , int);
void insertionSort(int *arr , int size)
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

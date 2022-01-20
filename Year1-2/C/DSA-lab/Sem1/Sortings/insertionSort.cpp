#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::endl;
int i,j;
void InsertionSort(int arr[],int size)
{
    int key;
    for(j=2;j<size;j++)
    {
        key = arr[j];
        i= j-1;
        while (i>0 && arr[i]>key)
        {


            arr[i+1] = arr[i];
            i=i-1;}
        arr[i+1] = key;
    }
}
void printarray(int arr[], int size)
{
    for(i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}
int main()
{
    int arr[] = {4,3,6 ,2,6,233,6,13,97,34,45};
    int size = (sizeof(arr)/sizeof(arr[0]));
    InsertionSort(arr,size);
    printarray(arr,size);
    return 0;
}

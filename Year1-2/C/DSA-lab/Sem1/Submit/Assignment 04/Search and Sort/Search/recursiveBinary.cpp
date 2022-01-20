#include<stdio.h>
#include<iostream>
using namespace std;
int _found(int *arr,int , int size , int);
int _found(int *arr,int l, int r , const int value)
{
    if(l>r) return -1;
    int mid = (l+r)/2;
    if(arr[mid]== value)
    {
        return (mid+1);
    }
    else if (arr[mid]>value)
    {
        r = mid-1;
        _found(arr,l,r,value);
    }
    else{
        l  = mid+1;
        _found(arr,l,r,value);
    }
}
int main()
{
	int arr[10];
	int i = 0;
	int size;
	int value= 6;
	while(i!= 10)
	{
		arr[i] = i;
		++i;
	}
	for(i = 0;i<10;++i)
    {
        printf("%d  ",arr[i]);
    }
	size = sizeof(arr)/sizeof(arr[0]);
	cout<<endl;
	printf("%d\n",_found(arr,0,size-1,value) );
	return 0;
}

#include<iostream>
using namespace std;
void sum(int *arr1 , int size1 ,int *arr2 ,int *arr3 );

int main()
{
    int arr1[5]  = {1,1,0,1,1};   //  1 0 1 1  0
    int arr2[5] =  {0,1,0,1,1};
    int arr3[6];
    sum(arr1,5,arr2,arr3);
    for(auto i : arr3)
        cout<<i<<" ";
}
void sum(int *arr1 , int size1 ,int *arr2 ,int *arr3 )
{
    int carry = 0;
    int i ;
    for(i = (size1-1) ; i >=  0;--i)
    {
        int temp = carry + arr2[i] + arr1[i];
        carry = temp/2;
        temp = temp%2;
        arr3[i+1] = temp;
    }
    arr3[i+1] = carry;
}

#include <stdio.h>
#include<iostream>
#include<fstream>
#include<chrono>
using namespace std;
#define arrSize 20000
int _found(int *, int  , int );
void readData()
{

    int arr[arrSize];
    ifstream read;
    read.open("sort.txt",ios::binary);

    if(read)
    {
        int i = 0;
        int temp;
        while(read>>temp)
        {
            arr[i] = temp;
            ++i;
        }
        read.close();

    }
    else{
        cout<<"Unable to open file.\n";
    }
    auto start = chrono::high_resolution_clock::now();
    cout<<_found(arr,0,arrSize,977957)<<endl;
    auto end = chrono::high_resolution_clock::now();

    auto diff = end - start;

    cout << chrono::duration <double, std::milli> (diff).count() << " ms" << endl;

    ofstream  write;
    write.open("sort.txt");
    if(write)
    {
        for(int i = 0 ; i < arrSize ; ++i)
        {
            write<<arr[i]<<endl;
        }
     //   long long int temp;
      //  static_cast<long long int >(diff);
       // long long int temp = chrono::duration_cast<std::chrono::milliseconds>(diff);
    }
    else{
        cout<<"Unable to open file.\n";
    }

}
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
	readData();
	return 0;
}

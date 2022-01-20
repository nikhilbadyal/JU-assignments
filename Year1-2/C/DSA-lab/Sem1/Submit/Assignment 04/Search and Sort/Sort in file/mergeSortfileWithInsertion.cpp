#include<iostream>
#include<fstream>
#include<chrono>
#define arrSize 20000
#include"insertionSort.c"
using namespace std;

void readData();
void merge(int * , int  , int   , int );
void mergeSort(int * , int ,int  );


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
    mergeSort(arr,0,arrSize);
    auto end = chrono::high_resolution_clock::now();

    auto diff = end - start;

    cout << chrono::duration <double, std::nano> (diff).count() << " ms" << endl;

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
void merge(int *arr , int l , int   m , int r)
{
    int sl = m-l+1;
    int sr = r-m;
    int left[10001];
    int right[10001];
    for(int i = 0 ; i< sl  ; ++i)
    {
        left[i] = arr[l+i];
    }
    for(int j = 0 ; j < sr ;++j)
    {
        right[j] = arr[m+1+j];
    }
    left[sl] = INT_MAX;
    right[sr] = INT_MAX;
    int   i, j ;
    i = j = 0;
    for(int k = l ; k <= r ; ++k)
    {
        if(left[i]<=right[j])
        {
            arr[k] = left[i];
            ++i;
        }
        else{
            arr[k] = right[j];
            ++j;
        }
    }

}
void mergeSort(int *arr , int l ,int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        if(m-l < 100 )
        {insertionSort(arr,m-l);}
        if(r-m<100)
        {insertionSort(arr,m-l);}
        merge(arr,l,m,r);
    }
}
int main()
{
    readData();
    return 0;
}

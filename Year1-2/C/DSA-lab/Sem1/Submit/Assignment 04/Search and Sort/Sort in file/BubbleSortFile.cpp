#include<iostream>
#include<fstream>
#include<chrono>
#define arrSize 20000
using namespace std;

void readData();
void merge(int * , int  , int   , int );
void bubbleSort(int * ,int  );
void swap(int * , int *);

void swap(int* x , int *y)
{
    int c = *x;
    *x = *y;
    *y = c;
}
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
    bubbleSort(arr,arrSize);
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
        if(flag) return ;
    }
}
int main()
{
    readData();
    return 0;
}













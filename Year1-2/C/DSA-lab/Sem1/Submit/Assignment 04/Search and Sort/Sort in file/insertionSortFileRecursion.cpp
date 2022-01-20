#include<iostream>
#include<fstream>
#include<chrono>
#define arrSize 20000
using namespace std;

void readData();
void insertionSort(int * , int );

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
    insertionSort(arr,arrSize);
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
void insertionSort(int *arr , int size)
{
    if(size == 1) return ;
    insertionSort(arr,size-1);
    int key = arr[size-1];
    int j = size -2 ;
    while(j>= 0 && arr[j] > key)
    {
        arr[j+1] = arr[j];
        j--;
    }
    arr[++j] = key;
}
int main()
{
    readData();
    return 0;
}

#include<iostream>
#include<fstream>
#include<chrono>
#define arrSize 20000
using namespace std;

void readData();
void selectionSort(int * , int );
void swap(int* x , int *y);


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
    selectionSort(arr,arrSize);
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
void selectionSort(int *arr , int size)
{
    for(int i = 0 ; i < size ;++i)
    {
        int min = i;
        for(int j = i+1 ; j < size ; ++j)
        {
            if(arr[min]>arr[j])
            {
                min = j;
            }
        }
        swap(&arr[i],&arr[min]);
    }
}
int main()
{
    readData();
    return 0;
}

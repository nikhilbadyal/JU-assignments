#include <stdio.h>
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
    _found(arr,arrSize,257319);
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
int _found(int *arr,int size,int search)
{
	int pos = -1;
	int i;
	for(i=1 ;i<=size;++i)
	{
		if(arr[i-1]==search){
			pos = i;
		    break;
		}

	}
	if (pos == -1)
	{
		printf("Value not present in array.\n");
		return 0;
	}
	return pos;


}
int main()
{
	readData();
	return 0;
}

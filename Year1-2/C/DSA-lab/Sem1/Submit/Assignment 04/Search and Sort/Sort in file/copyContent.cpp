#include<iostream>
#include<fstream>
#define Size 20000
using namespace std;

int main( )
{

    ifstream read;
    read.open("from.txt",ios::binary);
    ofstream  write;
    write.open("sort.txt",ios::binary);
    int count = 0;
    if(read && write )
    {


        for(int i = 0 ; i < Size ; ++i)
        {
            int temp;
            read>>temp;
            write<<temp<<endl;
            count++;
        }


    }
    else{
        cout<<"Unable to open file.\n";
    }
    cout<<count;
}

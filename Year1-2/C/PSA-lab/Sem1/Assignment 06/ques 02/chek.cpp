#include<iostream>
using std::cin; using std::cout;
using std::istream ; using std::ostream;


#include<fstream>
using std::ifstream ; using std::ofstream;

#include<fstream>
using std::fstream; using std::wfstream;

#include<vector>
using std::vector; using std::endl;

#include<algorithm>
using std::find_if; using std::max_element;

#include<string>
using std::string;

#include<utility>
using std::pair;

#include<tuple>
using std::tuple;

#include<ios>
using std::ios;




int main()
{
    ifstream read;
    int n;
    ofstream write;
    write.open("check.txt");
    while(cin>>n)
    {
        write<<n<<endl;
    }
    write.close();
    read.open("check.txt",ios::binary);

    auto old = read.tellg();
    auto pos = old;
    while(read>>n){
        if(n == 1)
        {
            pos = old;
            break;
        }
        old = read.tellg();
    }
    read.close();
 //   cout<<pos<<endl;
    write.open("check.txt",ofstream::in | ofstream::out);
    if(write.is_open()){
    write.seekp(pos);
    if(pos==0)
    {
        write<<90;
    }
    else{write<<endl<<90;} }
}

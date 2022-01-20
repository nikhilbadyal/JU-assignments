#include<iostream>
using namespace std;
class A
{

public:
//A() : arr{0},sizee(0) { cout<<"callled1";}
//A(int a , int b ) : arr{a},sizee(b) {cout<<"callled2\n";}
A(int a ) : sizee(a) {}
A(int a,int b) {for (int i=0;i<=3;i++)
arr[i]=a;
sizee = b;}
//private: cout<<"callled2";
    int arr[3];
    int sizee;
};
int main()
{
  //  A a;
    A b(6,4);
    A c(3);
  //  cout<<a.arr[2];
    cout<<b.arr[1];
    cout<<b.sizee;
    cout<<c.sizee;
}

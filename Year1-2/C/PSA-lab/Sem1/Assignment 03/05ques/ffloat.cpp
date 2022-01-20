#include<iostream>
using namespace std;

void f(float);
void f(float a)
{
	cout<<"inside f(float)\n";
}
void ch(int f, int c)
{
    cout<<"here";
}
void ch(char c , int d)
{

}
int main()
{
//	ch(1,1);
	ch('b','a');
	ch(1.4,1.4);

}

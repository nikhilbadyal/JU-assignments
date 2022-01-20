#include<iostream>
using namespace std;

int &max(int a,int b)
{
	return((a>b)?a:b);
}

int main()
{
	int a,b,c;

	cout<<"Enter the value of a and b : "<<"\n";
	cin>>a>>b;
	cout<<"value of a="<<a<<" and value of b="<<b<<"\n\n\n";
	c=max(a,b);
	cout<<"------------------Max("<<a<<","<<b<<") is given below-----------------"<<"\n";
	cout<<"When the result is stored in variable of type a and b : "<<c<<"\n";
	int &d=max(a,b);
	cout<<"When result is stored in variable referring to the type of a and b : "<<d;
}

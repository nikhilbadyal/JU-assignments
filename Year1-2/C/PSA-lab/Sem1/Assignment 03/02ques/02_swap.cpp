#include<iostream>
using namespace std;
void swap(int &no1,int &no2)
{
	int c = no1;
	no1 = no2;
	no2 = c;
}
int main()
{
	int no1,no2;
	cout<<"Enter two numbers :\n";
	cin>>no1>>no2;
	cout<<"Numbers before swappping are :\n";
	cout<<no1<<"\n"<<no2;
	
	swap(no1,no2);
	cout<<"\nNumbers after swappping are :\n";
	cout<<no1<<"\n"<<no2;
	return 0;
}

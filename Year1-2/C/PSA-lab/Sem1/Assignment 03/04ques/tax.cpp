#include<iostream>
#include<cstdlib>
using namespace std;

float tax_amount(float,float);
float tax_amount(float income,float tax_rate=10)
{
	float total;
	total=(income*(tax_rate/100));
	return(total);
}

int main()
{
	float tax_rate,income,total;
	int ch;
	cout<<"Enter the income : ";
	cin>>income;
	cout<<"Press 1 if you want to enter tax rate else press 2: ";
	cin>>ch;
	if(ch==1)
	{
		cout<<"Enter the tax_rate : ";
    	cin>>tax_rate;
    	total=tax_amount(income,tax_rate);
    	cout<<"Total tax amount is : "<<total;
    	exit(0);
	}
	total=tax_amount(income);
	cout<<"Total tax amount is : "<<total;
}

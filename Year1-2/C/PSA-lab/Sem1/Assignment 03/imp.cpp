#include<iostream>
#include<conio.h>
#define MAX 100
using namespace std;
class Store{
	public:
		static int count;
		void get_data();
		void print_data();
		int find();
//		static void add_item(int);
    private:
		int id;
		char name[30];
		float rate;
		int quantity;
};
void Store::get_data()
{
	count++;
	cout<<"Enter the id,name,rate and quantity of item:\n";
	cin>>id>>name>>rate>>quantity;
}
void Store::print_data()
{
///	cout<<"Item details :\n";
	cout<<"\n Id:  "<<id<<"\nName:  "<<name<<"\nRate:  "<<rate<<"\nQuantiy:  "<<quantity<<endl;
}
int Store::find()
{
	return id;
}
int search(Store *s,int n)
{
	int p=-1,id;
	cin>>id;
	for(int i=0;i<n;i++)
	{
		if(id==s[i].find())
		{
			p=i;
		}
	}
	if(p!=-1)
	{
		cout<<"Data found.\n";
		s[p].print_data();
		cout<<endl;
		return 0;
	}
	else{
		cout<<"Data Not found\n";
		return 1;
	}
}
int Store::count=0;
int main()
{
	Store s[MAX];
	int i,n,add,adds;
/*	cout<<"How many items do you have :\n";
	cin>>n;
	for(i=0;i<n;i++)
	{
		cout<<"Enter detais of item"<<i+1<<":\n";
		s[i].get_data();
	}
	cout<<"Enter the id of item you want to search.\n";
	i=search(s,n);
	if(i==1)
	{
		cout<<"Do you want to add this item.Press 1 to add.\n";
		cin>>add;
		if(add==1)
		{
			int a = Store::count;
			s[a].get_data();
		}
	}*/
	cout<<"How many items do you want to add.\n";
	cin>>adds;
	for(i=0;i<adds;i++)
	{
		cout<<"Enter the id of item you want to add.\n";
		i=search(s,n);
		if(i==1)
		{
			int a = Store::count;
	    	s[a].get_data();
		}

	}
	return 0;
}


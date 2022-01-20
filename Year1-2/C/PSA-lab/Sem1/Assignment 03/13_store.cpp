#include<iostream>
#include<string>
#define MAX 100
using namespace std;
class Store{
	private:
		int id;
		char name[30];
		float rate;
		int quantity;
	public:
		const int check_id(int);
		void get_data();
		const void print_data();
		static void add_item(int);

};
void Store::get_data()
{
	cout<<"Enter the id,name,rate and quantity of item:\n";
	cin>>id>>name>>rate>>quantity;
}
const void Store::print_data()
{
///	cout<<"Item details :\n";
	cout<<"id:  "<<id<<"Name:  "<<name<<"Rate:  "<<rate<<"Quantiy:  "<<quantity<<endl;
}
int main()
{
	Store s[MAX];
	int n,id,x,added;
	cout<<"How many items do you have :\n";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Enter details of item"<<i+1<<":\n";
		s[i].get_data();
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Details of item"<<i+1<<":\n";
		s[i].print_data();
	}
	cout<<endl;
	cout<<"Enter the unique id of the item.\n";
	cin>>id;

	return 0;
}

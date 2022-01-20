#include<iostream>
#include<conio.h>
#define MAX 100
using namespace std;
class Store{
	public:
        static int count;
		void set_data()
		{
            count++;
            cout<<count<<endl;
            cout<<"Enter the id,name,rate and quantity of item:\n";
            cin>>id>>name>>rate>>quantity;
         }
		void get_data()
		{
         	cout<<"Item details :\n";
            cout<<"\n Id:  "<<id<<"\nName:  "<<name<<"\nRate:  "<<rate<<"\nQuantiy:  "<<quantity<<endl;
        }
        void display_data()
        {
            get_data();
        }
		int find()
		{
		    return id;
		}
//		static void add_item(int);
    private:
		int id;
		char name[30];
		float rate;
		int quantity;
};
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
		s[p].display_data();
		cout<<endl;
		return 0;
	}
	else{
		return 1;
	}
}
int Store::count=0;
int main()
{

	Store s[10];
	int i,n,add=0,p,adds,x=1;
	Store::count;
	while(x==1)
    {

        cout<<"Enter 1 if you want to add\n";
        cout<<"Enter 2 if you want to search\n";
        cout<<"Enter 3 if you want to add more data.\n";
        cout<<"Enter 4 if you want to display data'.\n";
        cin>>p;
        switch(p)
        {
            case 1: cout<<"How many items do you have :\n";
                    cin>>n;
                    for(i=0;i<n;i++)
                    {
                        cout<<"Enter details of item"<<i+1<<":\n";
                        s[i].set_data();
                    }
                    cout<<Store::count<<endl;
                    break;
            case 2: cout<<"Enter the id of item you want to search.\n";
                    i=search(s,n);
                    if(i==1)
                    {
                        cout<<"Data Not found\n";
                        cout<<"Do you want to add this item.Press 1 to add.\n";
                        cin>>add;
                        if(add==1)
                        {
                              int a = Store::count;
                              s[a].set_data();
                        }
                    }
                    break;
            case 3: cout<<"How many items do you want to add\n";
                    cin>>add;
                    for(i=0;i<add;i++)
	                {
	                	cout<<"Enter the id of item you want to add.\n";
	                	i=search(s,n);
	                	if(i==1)
	                 	{
                            int a = Store::count;
                            s[a].set_data();
                        }
                        else{
                            cout<<"Id already allocated.\n";
                        }
                    }
                    break;
            case 4:
                    for(i=1;i<=(Store::count);i++){
                        s[i].display_data();
                    }
                    break;
        }
        cout<<"Enter 1 if you want to continue.\n";
        cin>>x;
    }
	return 0;
}


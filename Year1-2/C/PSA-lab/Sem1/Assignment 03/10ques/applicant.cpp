#include<iostream>
#include<cstdlib>
using namespace std;

class applicant
{
	static int id;
	static int total_number;
	char name[31];
	int score;
	public:

		void get_data(int n)
		{
			total_number++;
			if(n==1)
			{
				cout<<"Enter id : ";
				cin>>id;
			}
			cout<<"\n\n";
			cout<<"Enter the name of the applicant : ";
			cin>>name;
			cout<<"Enter score of the applicant : ";
			cin>>score;
			cout<<"\n\n";
		}

		void show_data(int i)
		{
			if(i==1)
		    {
		    	id--;
			}
			id++;
			cout<<"\n\n";
			cout<<"Id of the applicant "<<id<<"\n"<<"Name of the applicant is : "<<name<<"\n"<<"score of the applicat is "<<score;
			cout<<"\n\n";
		}

		void number_of_applicants()
		{
			cout<<"\n\n";
			cout<<"total number of applicants are : "<<total_number;
			cout<<"\n\n";
		}
};
int  applicant::id=0;
int applicant::total_number;

int menu()
{
	int ch;
	cout<<"Press 1 to get data : "<<"\n";
	cout<<"press 2 to display data : "<<"\n";
	cout<<"Press 3 to display total number of students : "<<"\n";
	cout<<"Press 4 to exit :"<<"\n";
	cout<<"Your choice : ";
	cin>>ch;
	return ch;
}

int main()
{
	int n=0;
	class applicant a[100];
	while(1)
	{
		switch(menu())
		{
			case 1: n++;
			        a[n].get_data(n);
			        break;

			case 2: for(int i=1;i<=n;i++)
		        	{
		        		a[i].show_data(i);
					}
					break;

			case 3: a[n].number_of_applicants();
			        break;

			case 4: exit(1);
			        break;

			case 5: cout<<"Enter valid number : ";
			        break;
		}
	}
}



















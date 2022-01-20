#include<iostream>
using namespace std;


struct student
{
	int roll;
	int score[5];

    void get_data(int r,int *s)
    {
    	roll=r;
    	for(int i=0;i<5;i++)
    	{
    		score[i]=s[i];
		}
	}

	void show_data()
	{
		cout<<"\n\n";
		cout<<"Roll of the student :"<<roll<<"\n";
		for(int i=0;i<5;i++)
		{
			cout<<"Marks in "<<i+1<<"subject  :"<<score[i]<<"\n";
		}
	}
};

student modify_data(student &p)
{
	cout<<"\n\n";

	int roll,score[5];
	cout<<"----------------------------------------------ENTER THE MODIFIED  DATA------------------------------------------------------"<<"\n";
	cout<<"Enter the roll of the student : ";
	cin>>roll;
	cout<<"-------------------Enter score of the student-----------------"<<"\n";
    for(int i=0;i<5;i++)
   	{
   		cout<<"Enter the marks in "<<i+1<<" subject : ";
   		cin>>score[i];
	}
	p.get_data(roll,score);
}

void show_modified_data(student q)
{
	cout<<"\n\n";

	cout<<"---------------------------------------------SHOWING MODIFFIED DATA-----------------------------------------------------------"<<"\n";
	cout<<"Roll of the student :"<<q.roll<<"\n";
	for(int i=0;i<5;i++)
	{
		cout<<"marks in "<<i+1<<"subject : "<<q.score[i]<<"\n";
	}
}

int main()
{
	student s;
	int roll,score[5];
	cout<<"Enter roll of the student : ";
   	cin>>roll;
   	cout<<"-------------------Enter score of the student-----------------"<<"\n";
   	for(int i=0;i<5;i++)
   	{
   		cout<<"Enter the marks in "<<i+1<<" subject : ";
   		cin>>score[i];
	}
	s.get_data(roll,score);
	s.show_data();
	modify_data(s);
	show_modified_data(s);

}

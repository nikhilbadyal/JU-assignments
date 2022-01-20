#include<iostream>
#include<cstdlib>
#define MAX 100
//#include"pre_check.c"
using namespace std;
class Student;
class Date{
public:

    friend class Student;
    void set_date()
    {
        cout<<"Enter day\n";
        cin>>day; //= pre_check(2);
        cout<<"Enter month.\n";
        cin>>month; // = pre_check(3);
        cout<<"Enter year.\n";
        cin>>year;
    }
    void show_date()
    {
        cout<<day<<"/"<<month<<"/"<<year<<"\n";
    }

private:
    int day;
    int month;
    int year;
};
class Student{
public:
    static int objcount;
    void set_data()
    {
        objcount++;
        cout<<"Enter the name of the student:\n";
        cin>>name;
        cout<<"Enter roll of the student:\n";
        cin>>roll;
        cout<<"Enter course of the student:\n";
        cin>>course;
        cout<<"Enter Data of admission:\n";
        void set_date();


    }
    const void display_data()
    {
        cout<<"Name:  "<<name<<"  Roll No.:  "<<roll<<"  Course:  "<<course<<"  Date of admission:  ";
        void show_date();
    }
    void set_mark()
    {
        cout<<"Enter marks in Maths:\n";
        cin>>marks[0];
        cout<<"Enter marks in Science:\n";
        cin>>marks[1];
        cout<<"Enter marks in English:\n";
        cin>>marks[2];
        cout<<"Enter marks in Hindi:\n";
        cin>>marks[3];
        cout<<"Enter marks in Computer:\n";
        cin>>marks[4];
    }
    const void show_marksheet()
    {
        cout<<"===================================================\n";
        cout<<"RollNo.: "<<roll<<"StudentName: "<<name<<endl;
        cout<<"---------------------------------------------------\n";
        cout<<"SUBJECT\t\t\tMARKS\n";
        cout<<"---------------------------------------------------\n";
        cout<<"Maths\t\t\t"<<marks[0]<<endl;
        cout<<"Science\t\t\t"<<marks[1]<<endl;
        cout<<"English\t\t\t"<<marks[2]<<endl;
        cout<<"Hindi\t\t\t"<<marks[3]<<endl;
        cout<<"Computer\t\t"<<marks[4]<<endl;
        cout<<"---------------------------------------------------\n";
        cout<<"TotalMarks:\t\t"<<(marks[0]+marks[1]+marks[2]+marks[3]+marks[4])<<endl;
        cout<<"===================================================\n";
    }
    const int find_ms()
    {
        return roll;
    }
private:
    int roll;
    char name[30];
    char course[30];
    int date;
    int marks[5];

};
int  Student::objcount=0;
int main()
{
    Student s[MAX];
    int n,ms,i,task;
    while(1)
	{
		cout<<"\nEnter 1 if you want to admit student.\n";
		cout<<"Enter 2 if you want to display data.\n";
		cout<<"Enter 3 if you want to add marks.\n";
		cout<<"Enter 4 if you want to see mark-sheet.\n";
		cout<<"Enter 5 if you want to see total no of admissions.\n";
		cout<<"Enter 6 to exit.\n";
		cin>>task;
	//	int task = pre_check(1);
		switch(task)
		{
			case 1: cout<<"How many students do you have:\n";
			        cin>>n;
                    for(i=0;i<n;i++)
                    {
                        s[i].set_data();
                    }
			        break;
			case 2: for(i=0;i<n;i++)
                    {
                        s[i].display_data();
                    }
			        break;
            case 3: for(i=0;i<n;i++)
                    {
                        s[i].set_mark();
                    }
                    break;
			case 4: cout<<"Enter the roll no of student whose mark-sheet you want to see.\n";
			        cin>>ms;
			        for(i=0;i<n;i++)
                    {
                        if(ms==s[i].find_ms())
                        {
                            s[i].show_marksheet();
                        }
                    }
			        break;
            case 5: cout<<"Total no. of admissions are "<< Student::objcount<<endl;
                //    break;
            case 6: exit(0);
		}
	}
    return 0;
}

#include<iostream>
#include"pre_check.c"
int type;
char type1[10] = "AM";
char type2[10] = "PM";
using namespace std;
int format;
class Time{
	public:
		void get_data()
		{
			cout<<"Entered time is.\n";
			cout<<"Hours : "<<hour<<"\tMinutes : "<<minute<<"\tseconds :"<<second<<"\t";
			if(type==1)
            {
                cout<<type1;
            }
            else{

                cout<<type2;
            }
		}
		int get_mint()
		{
			return minute;
		}
		void set_data()
		{
			cout<<"In which format you want to enter time.Enter 12 or 24.\n";
	        cin>>format;
	        if(format==12)
			{
				set_12data();
			}
			else if(format==24)
			{
				set_24data();
			}
			else{
				cout<<"OOPS! Wrong entry.\n";
				exit(0);
			}
		}
		void set_12data()
		{
			cout<<"Enter hour(s).\n";
			hour = pre_check(2);
			cout<<"Enter minute(s).\n";
			minute = pre_check(3);
			cout<<"Enter second(s).\n";
			second = pre_check(4);
			cout<<"Is it AM(1) or PM(2)\n";
			cin>>type;
		}
		void set_24data()
		{
			cout<<"Enter hour(s).\n";
			hour = pre_check(5);
			cout<<"Enter minute(s).\n";
			minute = pre_check(3);
			cout<<"Enter second(s).\n";
			second = pre_check(4);
		}
		void display_data()
		{
			get_data();
		}
		void add_min()
		{
		    if(hour==0 || minute==0 || second ==0)
            {
                cout<<"Please enter data at least once.\n";
                exit(0);
            }
			int add_mint,to_add,temp;
			cout<<"How many minutes you want to add in current time.\n";
			cin>>add_mint;

			if(format==12)
            {
                to_add = get_mint();
                temp = to_add + add_mint;
                if(temp>60)
                {
                hour = hour+ (temp/60);
                minute = temp%60;
                }
                if(hour>12)
                {
                    hour = hour%12;
                }
            }
            if(format==24)
            {
                to_add = get_mint();
                temp = to_add + add_mint;
                if(temp>60)
                {
                hour = hour+ (temp/60);
                minute = temp%60;
                }
                if(hour>24)
                {
                    hour = hour%24;
                }
            }
            cout<<"Entered time is.\n";
			cout<<"Hours : "<<hour<<"\tMinutes : "<<minute<<"\tseconds :"<<second<<"\t";
			if(type==1)
            {
                cout<<type2;
            }
            else{

                cout<<type1;
            }
		}
	private:
		int hour=0;
		int minute=0;
		int second=0;
};
int main()
{
	Time t;
	int format,task;
	while(1)
	{
		cout<<"\nEnter 1 if you want to set data.\n";
		cout<<"Enter 2 if you want to display data.\n";
		cout<<"Enter 3 if you want to add data.\n";
		cout<<"Enter 4 to exit.\n";
		task = pre_check(1);
		switch(task)
		{
			case 1: t.set_data();
			        break;
			case 2: t.display_data();
			        break;
			case 3: t.add_min();
			        break;
            case 4 : exit(0);
		}
	}
	return 0;
}

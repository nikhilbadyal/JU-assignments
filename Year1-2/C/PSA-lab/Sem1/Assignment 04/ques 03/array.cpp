#include<iostream>
#include"Array.h"
#include"pre.cpp"
#define MAX 2
int main()
{
    int task,i;
    Array s[MAX],s1;
    while(1)
	{
		cout<<"\nEnter 1 if you want to set data.\n";
		cout<<"Enter 2 if you want to display data.\n";
		cout<<"Enter 3 if you want to add data.\n";
		cout<<"Enter 4 if you want to subtract rate.\n";
		cout<<"Enter 5 if you want to assign array.\n";
		cout<<"Enter 6 if you want to know ith value in array.\n";
		cout<<"Enter 7 if you want to multiply scalar value to the array.\n";
		cout<<"Enter 8 to exit.\n";
		task = pre_check();
		switch(task)
		{
			case 1 :for(i=0;i<1;i++)
			        {
			            cout<<"Enter array "<<i+1<<endl;
			            //cin>>s[i];
			            cin>>s1;
			        }
			        break;
			case 2: for(i=0;i<1;i++)
			        {
			            cout<<"\nArray "<<i+1<<endl;
			            //cout<<s[i];
			            cout<<s1;
			        }
			        break;
			case 3: cout<<s[0]+s[1];
			        break;
            case 4: cout<<s1[3];
                   /*for(i=0;i>1;i++)
                    {
                        cout<<s[1][3];
                    }*/
                    break;
            case 5: cout<<5*s1;
                    break;
       //     case 5: cout<<s[0]=s[1];
                  //  break;

      /*      case 7: cout<<s;
                    break;*/
            case 6: exit(0);
		}
	}
}

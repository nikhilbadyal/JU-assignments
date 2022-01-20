#include<iostream>
#include"String2.h"
#include"pre.cpp"
#define MAX 2
int main()
{
    int task,n=1,a,i;
    String s[MAX],s1,s2;
    while(1)
	{
		cout<<"\nEnter 1 if you want to set data.\n";
		cout<<"Enter 2 if you want to display data.\n";
		cout<<"Enter 3 if to assign.\n";
		cout<<"Enter 4 if you want to concatinate.\n";
		cout<<"Enter 5 if you want to compare.\n";
		cout<<"Enter 6 to exit.\n";
		task = pre_check();
		switch(task)
		{
			case 1 :for(i=0;i<n;i++)
			        {
			            cout<<"Enter String "<<i+1<<endl;
			           // cin>>s[i];
			            cin>>s1;
			        }
			        cin>>s2;
			        break;
			case 2: for(i=0;i<n;i++)
			        {
			            cout<<"\nString "<<i+1<<endl;
			           // cout<<s[i];
			            cout<<s1;
			        }
			        break;
			case 3: cout<<s[0]+s[1];
			        break;
            case 4: s2=s1;
                    cout<<s2;
                    break;
            case 5: a = s2==s1;
                    if(a==1)
                    {
                        cout<<"Equal.\n";
                    }
                    else{
                        cout<<"Unequal.\n";
                    }
                    break;
            case 6: exit(0);
		}
	}
}

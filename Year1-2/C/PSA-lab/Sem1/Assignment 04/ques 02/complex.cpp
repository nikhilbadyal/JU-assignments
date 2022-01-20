#include<iostream>
#include<cstdlib>
#include"Complex.h"
#include"pre.cpp"
#define MAX 100
int main()
{
    Complex s[MAX];
    int rate,i=0,a,task,countt=0,quantiy,n,id;
    while(1)
	{
		cout<<"\nEnter 1 if you want to set data.\n";
		cout<<"Enter 2 if you want to display data.\n";
		cout<<"Enter 3 if you want to add data.\n";
		cout<<"Enter 4 if you want to subtract rate.\n";
		cout<<"Enter 5 to check equality.\n";
		cout<<"Enter 6 to check Inequality.\n";
		cout<<"Enter 7 to check Greater.\n";
		cout<<"Enter 8 to exit.\n";
		task = pre_check();
		switch(task)
		{
			case 1 : for(i=0;i<2;i++)
                    {
                        cout<<"Enter two numbers "<<(i+1)<<endl;
                        cin>>s[i];
                    }
			        break;
			case 2: cout<<"Numbers are \n"<<endl;
			        for(i=0;i<2;i++)
                    {
                        cout<<s[i]<<endl;
                    }
			        break;
			case 3: cout<<s[0]+s[1];
			        break;
            case 4: cout<<s[0]-s[1];
                    break;
            case 5: a=s[0]==s[1];
                    if(a==1)
                    {
                        cout<<"Equal.\n";
                    }
                    else{
                        cout<<"Unequal.\n";
                    }
                    break;
            case 6: a=s[0]!=s[1];
                    if(a==1)
                    {
                        cout<<"Unequal.\n";
                    }
                    else{
                        cout<<"Equal.\n";
                    }
                    break;
            case 7: a=s[0]>s[1];
                    if(a==1)
                    {
                        cout<<"Greater.\n";
                    }
                    else{
                        cout<<"Smaller.\n";
                    }
                    break;
            case 8: exit(0);

		}
	}
    return 0;
}

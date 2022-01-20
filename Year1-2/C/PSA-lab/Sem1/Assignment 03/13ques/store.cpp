#include<iostream>
#include<cstdlib>
#include"Store.h"
#include"pre.cpp"
#define MAX 100
int main()
{
    Store s[MAX];
    int rate,task,countt=0,quantiy,n,id;
    while(1)
	{
		cout<<"\nEnter 1 if you want to set data.\n";
		cout<<"Enter 2 if you want to display data.\n";
		cout<<"Enter 3 if you want to add data.\n";
		cout<<"Enter 4 if you want to update rate.\n";
		cout<<"Enter 5 if you want to update quantity.\n";
		cout<<"Enter 6 to exit.\n";
		task = pre_check();
		switch(task)
		{
			case 1: cout<<"How many items you want to add.\n";
                    cin>>n;
                    for(int i=0;i<n;i++)
                    {
                        cout<<"Enter details of item "<<(i+1)<<"(Code,Name,Quantity,Rate)"<<endl;
                        cin>>s[i];
                    }
			        break;
			case 2:
			        for(int i=0;i<(Store::objcount);i++)
                    {
                        cout<<s[i]<<endl;
                    }
			        break;
			case 3: cout<<"Enter id of item you want to add.\n";
                    cin>>id;
                    for(int i=0;i<((Store::objcount));i++)
                    {
                        if(s[i].code_ret() != id){countt =1; }
                        else{
                            cout<<"Item already exist.\n";
                            countt =0;
                            break;
                        }
                    }
                    if(countt==1)
                    {
                        cout<<"Enter id again.\n";
                        cin>>s[(Store::objcount)];
                    }
			        break;

            case 4: cout<<"Enter the unique code of item whose rate you want to update.\n";
                    cin>>id;
                    for(int i=0;i<((Store::objcount));i++)
                    {
                        if(s[i].code_ret() == id){

                            cout<<"Enter the rate of item.\n";
                            cin>>rate;
                            s[i].update_rate(rate);
                            countt=1;
                            break; }
                    }
                    if(countt==0)
                    {
                        cout<<"Item doesn't exist.\n";
                    }
			        break;
            case 5: cout<<"Enter the unique code of item whose quantity you want to update.\n";
                    cin>>id;
                    for(int i=0;i<((Store::objcount));i++)
                    {
                        if(s[i].code_ret() == id){

                            cout<<"Enter the quantity of item.\n";
                            cin>>rate;
                            s[i].update_quant(rate);
                            countt=1;
                            break; }
                    }
                    if(countt==0)
                    {
                        cout<<"Item doesn't exist.\n";
                    }
			        break;
            case 6: exit(0);
		}
	}
    return 0;
}

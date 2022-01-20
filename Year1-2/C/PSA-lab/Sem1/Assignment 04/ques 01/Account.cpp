#include<iostream>
#include<string>
#define MAX 100
#include"pree.c"
#include<cstdlib>
#include"Account.h"
int main()
{
    int balan,task,countt=0,input,n,id;
    while(1)
	{
		cout<<"\nEnter 1 if you want to add data.\n";
		cout<<"Enter 2 if you want to display data.\n";
		cout<<"Enter 3 if you want to add new data.\n";
		cout<<"Enter 4 if you want to update details.\n";
		cout<<"Enter 2 if you want to search an account.\n";
		cout<<"Enter 5 to exit.\n";
		task = pre_check();
		switch(task)
		{
			case 1: cout<<"How many items you want to add.\n";
                    cin>>n;
                    for(int i=0;i<n;i++)
                    {
                        cout<<"Enter details of Account"<<(i+1)<<"(Account number, Amount)"<<endl;
                        cin>>Item_list.s[i];
                    }
			        break;
			case 2: for(int i=0;i<(Account::objcount);i++)
                    {
                        cout<<s[i]<<endl;
                    }
			        break;
			case 3: cout<<"Enter Account number of item you want to add.\n";
                    cin>>id;
                    for(int i=0;i<((Account::objcount));i++)
                    {
                        if(s[i].accn_ret() != id){countt =1; }
                        else{
                            cout<<"Item already exist.\n";
                            countt =0;
                            break;
                        }
                    }
                    if(countt==1)
                    {
                        cout<<"Enter Account number again.\n";
                        cin>>s[(Account::objcount)];
                    }
			        break;

            case 4: cout<<"Enter the Account number whose balance you want to update.\n";
                    cin>>id;
                    for(int i=0;i<((Account::objcount));i++)
                    {
                        if(s[i].accn_ret() == id){

                            cout<<"Enter the  new balance.\n";
                            cin>>balan;
                            s[i].update_bal(balan);
                            countt=1;
                            break; }
                    }
                    if(countt==0)
                    {
                        cout<<"Item doesn't exist.\n";
                    }
			        break;
            case 5: cout<<"Enter the account number to search.\n";
                    cin>>id;
                    for(int i=0;i<((Account::objcount));i++)
                    {
                        if(s[i].accn_ret() == id){
                                cout<<"Data found.\n";
                                cout<<"Enter 1 to if you want to see his details.";
                                cin>>input;
                                if(input==1)
                                {
                                    cout<<s[i]<<endl;
                                }
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

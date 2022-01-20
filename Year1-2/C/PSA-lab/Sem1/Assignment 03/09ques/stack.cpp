#include<iostream>
#include<stdlib.h>
using namespace std;

class stack
{
	int top;
	int *arr;
	int capacity;
	public :
	void create_stack(int n)
	{
		arr=(int *)malloc(n*sizeof(int));
		top=-1;
		capacity=n;

		cout<<"stack created : "<<"\n\n";

	}

	void initalize(int n)
	{
		cout<<"\n\n";
		cout<<"Enter the elements one by one :"<<"\n";

		for(int i=0;i<n;i++)
		{
			top++;
			cin>>arr[i];
		}
		cout<<"\n\n";
	}

	int check_overflow()
	{
		if(top==(capacity-1))
		{
			cout<<"\n\n"<<"STACK OVERFLOW"<<"\n\n";
			return(0);
		}
		return(1);
	}

	int check_underflow()
	{
		if(top==-1)
		{
			cout<<"\n\n"<<"STACK UNDERFLOW"<<"\n\n";
			return(0);
		}
		return(1);
	}
	void push(int item)
	{
		top++;
		arr[top]=item;
		cout<<"\n\n"<<"ITEM PUSHED : "<<"\n\n";
	}

	void pop()
	{

		top--;
		cout<<"\n\n"<<"ITEM POPPED :"<<"\n\n";
	}

	void display()
	{
		int check=check_underflow();
		if(check==1)
		{
			cout<<"\n\n\n"<<"STACK IS :"<<"\n";
			for(int i=top;i>=0;i--)
	     	{
		    	cout<<arr[i]<<"\n";
	     	}
	        	cout<<"\n\n\n";
		}

	}
};
int menu()
{
	int ch;
	cout<<"press 1 to create stack : "<<"\n";
	cout<<"press 2 to push an element : "<<"\n";
	cout<<"Press 3 to pop an element : "<<"\n";
	cout<<"Press 4 to display stack : "<<"\n";
	cout<<"press 5  to inatilize whole stack :"<<"\n";
	cout<<"press 6 to exit  : "<<"\n";
	cout<<"your choice :";
	cin>>ch;
	return(ch);

}
int main()
{
	int n,item,check;
	stack s;
	while(1)
	{
		switch(menu())
		{
			case 1: cout<<"\n\n";
			        cout<<"Enter the capacity of stack :";
			        cin>>n;
			        s.create_stack(n);
			        break;

			case 2: check=s.check_overflow();
			        if(check==1)
			        {
			        	cout<<"\n\n";
			           cout<<"Enter the element that you want to push : ";
			           cin>>item;
				       s.push(item);
					}
					break;


			case 3: check=s.check_underflow();
			        if(check==1)
			        {
			        	s.pop();
					}
			        break;

			case 4: s.display();
			        break;

			case 5: s.initalize(n);
			        break;

			case 6: exit(1);
			        break;

			default : cout<<"Enter correct number : ";
			        break;
		}
	}
}














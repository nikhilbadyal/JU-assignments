#include <iostream>
#include <cstdlib>
//#include"pre.c"
using namespace std;

class Node
{
public:
    int data;
    Node* next;
};
class Linked_list{
private:
    Node *head,*p1;
public:
    Node* create_list();
    void print_list(Node *poly1);
    void delete_n(int);
    void add_n(int);
    void delete_num(int);
    void search_num(int);

};
Node* Linked_list::create_list()
{
    int i;

    do{
        Node *temp = new Node;
		int d=1;
        cout<<"Enter element : \n";
        cin>>temp->data;
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
			p1=temp;
		}
		else{
			p1->next=temp;
			p1=temp;
		}
		cout<<"Do you want one more term.\nEnter 1 to enter more.\n";
		cin>>i;
		if(i==0)
		{
			return head;
		}

	}while(i==1);
}
void Linked_list::print_list(Node* poly1)
{
	Node *p1;
	p1=poly1;
	while(p1!=NULL)
	{
	    cout<<p1->data;
		p1=p1->next;
    }
}
int main()
{
    Node *l;
    Linked_list s;
    while(1)
	{
		cout<<"\nEnter 1 if you want to create list.\n";
		cout<<"Enter 2 if you want to print list.\n";
		cout<<"Enter 3 if you want to delete nth node.\n";
		cout<<"Enter 4 if you want to add node at nth position.\n";
		cout<<"Enter 5 if you want to delete a number.\n";
		cout<<"Enter 6 if you want to search number.\n";
		cout<<"Enter 7 to exit.\n";
		//task = pre_check();
		int task;
		cin>>task;
		switch(task)
		{
			case 1: l = s.create_list();
			        break;
			case 2: s.print_list(l);
			        break;
			case 3:
			        break;

            case 4:
			        break;
            case 5:
			        break;
            case 6:
                    break;
            case 7: exit(0);
		}

     }
     return 0;
}

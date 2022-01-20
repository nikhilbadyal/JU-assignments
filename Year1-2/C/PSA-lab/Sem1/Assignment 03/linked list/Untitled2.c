








    #include <iostream>
#include <cstdlib>
class Node
{
public:
    int data;
    Node* next;

};

using namespace std;

class LinkedList
{
public:
    int length;
    Node *head;

    LinkedList();
    void add(int data);
    void print();
    void delete_n(int n);
    void add_n(int data,int position);
    void delete_no(int no);
    void search_no(int );
};

LinkedList::LinkedList(){
    this->length = 0;
    this->head = NULL;
}


int main()
{
    while(1)
	{
		cout<<"\nEnter 1 if you want to create list.\n";
		cout<<"Enter 2 if you want to print list.\n";
		cout<<"Enter 3 if you want to delete nth node.\n";
		cout<<"Enter 4 if you want to add node at nth position.\n";
		cout<<"Enter 5 if you want to delete a number.\n";
		cout<<"Enter 6 if you want to search number.\n";
		cout<<"Enter 7 to exit.\n";
		task = pre_check();
		switch(task)
		{
			case 1: LinkedList* list = new LinkedList();
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
            case 6:
                    break;
            case 7: exit(0);
		}

    for (int i = 0; i < 100; ++i)
    {
        list->add(rand() % 100);
    }
 //   list->delete_n(3);
    list->add_n(110,1);
 //   list->delete_no(82);
 //   list->search_no(4188);
    list->print();
    std::cout << "List Length: " << list->length << std::endl;
    delete list;
    return 0;
}

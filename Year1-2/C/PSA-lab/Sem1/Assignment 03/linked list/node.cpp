#include<iostream>
#include"pre_check.c"
#define MAX 200
using namespace std;
class Node{
public:
    int data;
    class Node* link;
};
Node* head;
class Linked_list(){
public:
    void create()
    {

    }
    void display();
    void add_at_n();
    void delete_at_n();
    void search_list();
    void delete_key();
    friend class Node;
};
int main()
{
    Node s[MAX]
    while(1)
	{
		cout<<"\nEnter 1 if you want to create list.\n";
		cout<<"Enter 2 if you want to display list.\n";
		cout<<"Enter 3 if you want to add node at nth position.\n";
		cout<<"Enter 4 if you want to delete node at nth position.\n";
		cout<<"Enter 5 if you want to search in list.\n";
		cout<<"Enter 6 if you want to delete node by key.\n";
		cout<<"Enter 7 to exit."
		int task = pre_check(1);
		switch(task)
		{
			case 1: cout<<" Input the number of nodes : ";
			        cin>>n;
                    for(i=0;i<n;i++)
                    {
                        s[i].create();
                    }
			        break;
			case 2: for(i=0;i<n;i++)
                    {
                        s[i].create();
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
            case 5: cout<<"Total no. of admissions are "<<Student::count;
                    break;
            case 6: exit(0);
		}
	}
    return 0;
}

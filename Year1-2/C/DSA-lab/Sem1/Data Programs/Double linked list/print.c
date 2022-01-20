#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};
struct Node *head=NULL;
struct Node * GetNewNode(int x)
{
    struct Node* NewNode= (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = x;
    NewNode->prev=NULL;
    NewNode->next=NULL;
    return NewNode;
}
void InsertAtTail(int x)
{
    struct Node * lnode = GetNewNode(x);
    if(head==NULL)
    {
        head = lnode;
        return ;
    }
    struct Node * temp = head;
    while(temp->next!=NULL) {temp=temp->next;}
    temp->next = lnode;
    lnode->prev = temp;
}
void Print()
{
    struct Node * temp = head;
    printf("List is : \n");
    while(temp!= NULL)
    {
        printf(" %d",temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void del_beg()
{
    head = head->next;
}
void del_end(struct Node* temp)
{
   temp->next =  NULL;
}
void delete(int n)
{
    int i;
    if(n==1) { del_beg(); return ;}
    struct Node* temp = head;
    for(i=0;i<n-2;i++) {temp = temp->next;}
    struct Node* temp1 = temp->next;
    if(temp1->next==NULL){ del_end(temp); return ;}
    temp->next = temp1->next;
    temp1->next->prev = temp1->prev;
}
int main()
{
    head = NULL; // empty list. set head as NULL.
	/*InsertAtHead(2); Print(); ReversePrint();
	InsertAtHead(4); Print(); ReversePrint();
	InsertAtHead(6); Print(); ReversePrint();
	InsertAtHead(8); Print(); ReversePrint();*/
	InsertAtTail(2);
	InsertAtTail(4);
	InsertAtTail(5);
	InsertAtTail(6);
	InsertAtTail(7);
//	InsertAtHead(6);  ReversePrint();
	InsertAtTail(8);
	Print();

	delete(3);
	Print();
    return 0;
}

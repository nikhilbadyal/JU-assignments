#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int i;
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};struct Node *head1,*last,*head2,*head,*head3,*head4;
typedef struct Node node;
void Print(node* head)
{
    int check = 0;
 //  int check = check_empty(head);
    if(check != 1)
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
}
struct Node * GetNewNode(int x)
{
    struct Node* NewNode= (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = x;
    NewNode->prev=NULL;
    NewNode->next=NULL;
    return NewNode;
}
node*  InsertAtHead(node* head,int x)
{
    struct Node * fnode = GetNewNode(x);
    if(head==NULL)
    {
        head = fnode;
        return head;
    }
    head->prev = fnode;
    fnode->next = head;
    head = fnode;
    return head;
}
node* split(node* source , node** frontsp , node** backsp)
{
    node * slow = source;
    node * fast = source->next;
    while(fast!=NULL)
    {
        fast = fast->next;
        if(fast!=NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontsp = source;
    *backsp = slow->next;
    slow->next->prev = NULL;
    slow->next = NULL;
}
node * merge_sorted(node * head1, node* head2)
{
    node * s;
    node * new_head   = NULL;
    if(head1->data>head2->data)
    {
        s = head2;
        head2 = head2->next;
    }
    else{
        s = head1;
        head1 = head1->next;
    }
    new_head = s;
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data >  head2->data)
        {
            s->next = head2;
            head2->prev = s;
            s = head2;
            head2 = head2->next;
        }
        else{
            s->next = head1;
            head1->prev = s;
            s = head1;
            head1 = head1->next;
        }
    }
    if(head1==NULL) s->next = head2;
    if(head2==NULL) s->next = head1;
    return new_head;
}
node * merge_sort(node * head)
{
    node * temp = head;
    node * a;
    node * b;

    if ((temp == NULL) || (temp->next == NULL)) {
        return head;}
    split(head,&a,&b);
    a = merge_sort(a);
    b = merge_sort(b);
    head = merge_sorted(a,b);
 //   return head;
}
int main()
{
    head2 = InsertAtHead(head2,100);
	head2 = InsertAtHead(head2,3);
	head2 = InsertAtHead(head2,56);
	head2 = InsertAtHead(head2,25);
	head2 = InsertAtHead(head2,5);
	head2 = InsertAtHead(head2,58);
	head2 = InsertAtHead(head2,173);
	head2 = InsertAtHead(head2,957);
	head2 = InsertAtHead(head2,463);


	head3 = InsertAtHead(head3,60);
	head3 = InsertAtHead(head3,40);
	head3 = InsertAtHead(head3,20);
	head3 = InsertAtHead(head3,50);
	head3 = InsertAtHead(head3,30);
	head3 = InsertAtHead(head3,10);


	head4 = InsertAtHead(head4,100);
	head4 = InsertAtHead(head4,60);
	head4 = InsertAtHead(head4,40);
	head4 = InsertAtHead(head4,20);

    Print(head2);
    head2 = merge_sort(head2);
   Print(head2);
}

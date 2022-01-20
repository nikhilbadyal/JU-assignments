#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};struct Node *head1,*last,*head2,*head,*head3;
typedef struct Node node;
struct Node * GetNewNode(int x)
{
    struct Node* NewNode= (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = x;
    NewNode->prev=NULL;
    NewNode->next=NULL;
    return NewNode;
}
void create()
{
    int n;
    printf("How many nodes do you want.\n");
    scanf("%d",&n);
    int i, data;
    node *newNode;

    if(n >= 1)
    {
        head = (node *)malloc(sizeof(node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        last = head;
        for(i=2; i<=n; i++)
        {
            newNode = (node *)malloc(sizeof(node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; // Link new node with the previous node
            newNode->next = NULL;

            last->next = newNode; // Link previous node with the new node
            last = newNode; // Make new node as last node
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}
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
void ReversePrint()
{
    struct Node *temp = head;
    if(temp==NULL) return ;
    while(temp->next!=NULL) {temp=temp->next;}
    printf("Reversed list is:\n");
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
int size(node* head)
{
    int i=0;
    node * temp = head;
    while(temp!=NULL)
    {
        i++;
        temp = temp->next;
    }
    return i;
}
bool equality(node * head1, node* head2)
{
    int flag =0;
    while(head1!=NULL && head2!= NULL)
	{
	    if(head1->data!=head2->data){ return false;}
	    head1 = head1->next;
	    head2 = head2->next;
	}
	return (head1 ==NULL && head2 == NULL);
}
bool search_sorted(node* head, int x)
{
    node* current = head;  // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
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
    return head;
}
bool search_unsorted(node* head, int x)
{
    head = merge_sort(head);
    return search_sorted(head,x);
}
node* append_list(node* head1,node* head2)
{
    node *temp=head1;
    while(temp->next!=NULL) {temp = temp->next;}
    temp->next = head2;
    head2->prev = temp;
    return head1;
}
node* delete_front(node* head)
{
    node * temp = head;
		head=head->next;
		if(head!=NULL)
        {
            head->prev = NULL;
        }
        free(temp);
		return head;
}
void del_las(node * last)
{
    printf("HII");
    node * todelete = last;
    last = last->prev;
    if(last!=NULL)
    {
        last->next = NULL;
    }
    free(todelete);
    return ;

}
node* delete_last(node* head)
{
    node * temp = head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    del_las(temp);
    return head;
}

node* delete(node * head,int n)
{
    int check =0;
 //   int check = check_empty(head);
    if(check != 1)
    {
        int i;
        if(n==1)
            { head =  delete_front(head);
          return head;
          }
        struct Node* temp = head;

        for(i=0;i<n-2;i++) {temp = temp->next;}

        struct Node* temp1 = temp->next;

        if(temp1->next==NULL)
            { del_las(temp1);
              return head; }
        temp->next = temp1->next;
        temp1->next->prev = temp1->prev;
        return head;
    }
}
bool ascend(node* head){
    while(head!=NULL && head->next != NULL)
    {
        if(head->data>head->next->data) {return true;} //NOt Ascend
        head = head->next;
    }

}
bool descend(node * head){
    while(head!=NULL && head->next != NULL)
    {
        if(head->data<head->next->data) {return true;} //NOt DEScend
        head = head->next;
    }

}
bool is_sorted(node* head)
{
    int i;
    if(ascend(head))
    { if(descend(head))
       {
        printf("Array unordered.\n");
        }
        else{printf("Array in Descending order.");}
    }
    else{
        printf("Array in Ascending order.");
    }
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
node * InsertAtN(node* head,int n)
{
    int value,i;
    node * temp = head;
    printf("Enter the value you want to insert,\n");
    scanf("%d",&value);
    if(n==1) {head = InsertAtHead(head,value); return head;}
    node *insert = GetNewNode(value);
    for(i=0;i<n-2;i++)
    {
        temp = temp->next;
    }
    insert->prev = temp->next->prev;
    insert->next = temp->next;
    temp->next = insert;
    return head;
}
node*  InsertAtTail(node* head,int x)
{
    struct Node * lnode = GetNewNode(x);
    if(head==NULL)
    {
        head = lnode;
        return head;
    }
    struct Node * temp = head;
    while(temp->next!=NULL) {temp=temp->next;}
    temp->next = lnode;
    lnode->prev = temp;
    return head;
}
node * remove_dup(node * head)
{
    if(head == NULL) { printf("List Empty."); return head; }
    node * temp = head;
    node *temp1 = NULL;
    while(temp->next !=NULL)
    {
        if(temp->data == temp->next->data)
        {
            temp1 = temp->next->next;
            if(temp->next->next!=NULL){
                temp->next->next->prev = temp->next->prev;
            }
            free(temp->next);
            temp->next = temp1;
        }
        else{

            temp = temp->next;
        }
    }
    return head;

}
node * moveLtoF(node * head)
{
    node * temp1= head;
    node * temp2= head->next;
    node * temp3 = head;
    while(temp2->next!=NULL)
    {
        temp2= temp2->next;
        temp1= temp1->next;
    }
    head = temp2;
    head->next = temp3;
    head->prev->next = NULL;
    head->prev = NULL;
    head->next->prev = head;
    return head;
}
node * del_alt(node * head)
{
    node *temp = head;
    node *temp1 = head->next;
    while(temp!=NULL && temp1!=NULL)
    {
        temp->next = temp1->next;
        temp1->next->prev = temp1->prev ;
        free(temp1);

        temp= temp->next;
        if(temp!=NULL)
        {
            temp1= temp->next;
        }
    }
    return head;
}
node * moveFtoL(node * head)
{
    node * temp1 = head;
    node * temp2 = head->next;
    while(temp1->next!=NULL)
    {
        temp1= temp1->next;

    }
    temp1->next = head;
    head = temp2;
    head->prev = NULL;
    temp1->next->next =NULL;
    temp1->next->prev = temp1;
    return head;
}
node* rotate(node* head)
{
    int n,i;
    printf("Enter key value:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head = moveFtoL(head);
    }
    return head;
}
void  del_list(node* head)
{
    if(head==NULL) return ;
	del_list(head->next);
	free(head);
	printf("List deleted.");
}
bool check_empty(node* head)
{
    if(head==NULL)
        return true;
    return false;
}
bool is_last(struct Node* curr )
{
    if(curr->next == NULL)
        return true;
    return false;
}

/*
bool search_unsorted(node* head, int x)
{
    node* current = head;  // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}
bool not_equal(node * head1,node * head2)
{
    return !equality(head1,head2);
}*/

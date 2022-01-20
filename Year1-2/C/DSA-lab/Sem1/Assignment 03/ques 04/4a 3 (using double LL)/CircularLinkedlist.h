#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node *next;
};struct Node *head1,*last,*head2,*head,*head3,*head4;
typedef struct Node  node;
node * GetNewNode(int x)
{
    struct Node* NewNode= (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = x;
    NewNode->next=NULL;
    return NewNode;
}
node* create_list(node* head)
{
    int i, num,n=5;
    node *last, *newnode;

    if(n >= 1)
    {
        head = (node *)malloc(sizeof(node));
        printf(" Input data for node 1 : ");
        scanf("%d", &num);
        head->data = num;
        head->next = NULL;
        last = head;
        for(i=2; i<=n; i++)
        {
            newnode = (node *)malloc(sizeof(node));
            printf(" Input data for node %d : ", i);
            scanf("%d", &num);
            newnode->data = num;
            newnode->next = NULL;	// next address of new node set as NULL
            last->next = newnode;	// previous node is linking with new node
            last = newnode;   		// previous node is advanced
        }
        last->next = head; 		//last node is linking with first node
    }
    return head;
}
void print_same(node* head)
{
	node *temp = head;
	printf("List is :\n");
	do{
		printf("  %d",temp->data);
		temp = temp->next;
	}while(temp!=head);
	printf("\n");
}
int size(node* head)
{
    node *temp = head;
    int i =0;
    do{
	    temp = temp->next;
		i++;
	}while(temp!=head);
	//printf("%d",i);
	return i;
}
bool equality(node*head1,node*head2)
{
    int i =0;
    node * temp1= head1;
    node * temp2= head2;
    if(size(temp1)== size(temp2))
    {
        do
	    {
	    if(temp1->data!=temp2->data){ return false;}
	    temp1 = temp1->next;
	    temp2 = temp2->next;
      	}while(temp1!=head1 && temp2!= head2);

        return (temp1 == head1 && temp2 == head2);
    }
    else {
        return false;
    }
}
bool search_sorted(node* head, int x)
{
    int i=0;
    node* current = head;  // Initialize current
    do{
        if(x<current->data)
        {
            return false;
        }
        else{
            if(current->data==x){ return true;}
            current = current->next;
        }}while(current!=head);
        return false;


}
bool search_unsorted(node* head, int x)
{
    int i=0;
    node* current = head;  // Initialize current
    do{
            if(current->data==x){ return true;}
            current = current->next;
        }while(current!=head);
        return false;
}
node * append_list(node* head1,node* head2)
{
    node *temp=head1;
    node *temp1=head2;
    do{
		temp = temp->next;
	}while(temp->next!=head1);
    temp->next = head2;
    do{
		temp1 = temp1->next;
	}while(temp1->next!=head2);
	temp1->next = head1;
    return head1;
}
node* insert_front(node* head,int x)
{
	node* temp1 = (node*)malloc(sizeof(node));
//	*(temp).data = x;
    temp1->data = x;
    temp1->next = head;
  //  temp->next = head;
//	*(temp).next = NULL;
	if(head==NULL){ temp1->next = temp1; head = temp1; return head;}
	node *temp2 = head;
    while(temp2->next != head)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    head = temp1;
  //  head->next = temp2;
//  temp-> = x;
    return head;
}
node* insert_n(node* head,int data,int position)
{
    printf("holy");
	int i;
	node* temp1 = (node*)malloc(sizeof(node));
	temp1->data=data;
	temp1->next = NULL;
	if(position==1)
	{
		temp1->next = head;

		head = temp1;
		return head;
	}
	node* temp2 = head;
	for(i=0;i<position-2;i++)
	{
		temp2= temp2->next;
	}
	temp1->next =temp2->next;
	temp2->next = temp1;
	return (head);
}
node * insertAtEnd(node* head1,int x)
{
    node * temp1= head1;
    node* temp = (node*)malloc(sizeof(node));
    temp->data = x;

	while(temp1->next!=head1)
    {
       temp1= temp1->next;
    }
    temp1->next = temp;
    temp->next = head1;
    return (head1);
}
node* delete_front(node* head)
{
    node* temp = head;
    node* temp1 = head;
    head=head->next;
    temp = head;
    do{
		temp = temp->next;
	}while(temp->next!=temp1);
	temp->next = head;
    free(temp1);  //Issue
    return head;
}
node* delete_nth(node* head,int n)
{
	int i;
	node* temp1 = head;
	if(n==1)
	{
		head= delete_front(head);
		return head;
	}
	for(i=0;i<n-2;i++)
	{
		temp1 = temp1->next;
	}
	node* temp2 = temp1->next;
	temp1->next=temp2->next;
	free(temp2);
	return head;
}
node* delete_last(node* head)
{
	node* temp = head;
    node* temp1 = head->next;
    node* temp2 = head;
	do{
		temp1 = temp1->next;
		temp2 = temp2->next;
	}while(temp1->next!=temp);
	temp2->next=temp1->next;
	free(temp1);
	return head;
}
bool ascend(node* head){
    int i=0;
    node* temp = head;
    do{
        if(temp->data>temp->next->data) {return true;} //NoT ascend
		temp = temp->next;
	}while(temp->next->next!=head);
	return false;
}
bool descend(node * head){
    int i=0;
    node* temp = head;
    do{
        if(temp->data<temp->next->data) {return true;} //NoT ascend
		temp = temp->next;
	}while(temp->next->next!=head);
	return false;
}
bool is_sorted(node* head)
{
    int i;
    if(ascend(head))
    { if(descend(head))
       {
        printf("Array unordered.\n");
        }
        else{printf("Array in Descending order.\n");}
    }
    else{
        printf("Array in Ascending order.\n");
    }
}
node* remove_dup(node * head)
{
    if(head == NULL) { printf("List Empty."); return head; }
    node * temp = head;
    node *temp1 = NULL;
    do
    {
        if(temp->data == temp->next->data)
        {
            temp1 = temp->next->next;
            free(temp->next);
            temp->next = temp1;
        }
        else{

            temp = temp->next;
        }
    }while(temp->next !=head);
    return head;
}
node * moveLtoF(node* head)
{
    node * temp1= head;
    node * temp2= head->next;
    node * temp3 = head;
    do{
		temp2= temp2->next;
        temp1= temp1->next;
	}while(temp2->next!=head);
    head = temp2;
    temp2->next = temp3;
    temp1->next =  temp2;
    return head;
}

node * del_alt(node * head)
{
    node *temp = head;
    node *temp1 = head->next;
    do
    {
        temp->next = temp1->next;
        free(temp1);

        temp= temp->next;
        if(temp!=NULL)
        {
            temp1= temp->next;
        }
    }while(temp!=head && temp1!=head);
    return head;
}
node * moveFtoL(node * head)
{
    node * temp1 = head;
    node * temp2 = head->next;
    do
    {
        temp1= temp1->next;

    }while(temp1->next!=head);
    temp1->next = head;
    head = temp2;
    temp1->next->next =head;
    return head;
}
node * rotate(node* head)
{
    int n,i;
    printf("Enter key value:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head = moveFtoL(head);
    }
    return head;
}/*
void  del_list(node* head)
{
    if(head==NULL) return ;
	del_list(head->next);
	free(head);
	printf("List deleted.");

}*/
node* recursion(node* head){
    if(head->next == NULL){

        return head;
    }

    node* newHead = recursion(head->next);
    head->next->next = head;
    head->next = newHead;
 //   newHead->next = head;
    return newHead;
}/*

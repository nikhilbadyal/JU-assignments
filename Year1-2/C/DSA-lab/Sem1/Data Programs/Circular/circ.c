#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node *next;
};struct Node *head1,*last,*head2,*head,*head3;
typedef struct Node  node;
node * GetNewNode(int x)
{
    struct Node* NewNode= (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = x;
    NewNode->next=NULL;
    return NewNode;
}
node * Empty_insert(node * last , int data)
{
    last = GetNewNode(data);
    last->next = last;
    return last;
}
node * insert_front(node * last,int data)
{
    if (last == NULL)
		return Empty_insert(last, data);
    node * tobeinserted = GetNewNode(data);
    tobeinserted->next = last->next;
    last->next = tobeinserted;
    return last;
}
node *insertAtEnd(node* last,int data)
{
    node * tobeinserted = GetNewNode(data);
    tobeinserted->next = last->next;
    last->next = tobeinserted;
    last = tobeinserted;
    return last;
}
node* insert_n(node* last,int data,int position)
{
    node * head = last->next;
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
	return (last);
}
void print_same(node* last)
{
    node * head = last->next;
	node *temp = head;
	printf("List is :\n");
	do{
		printf("  %d",temp->data);
		temp = temp->next;
	}while(temp!=last->next);
	printf("\n");
}/*
void reverse_print_helper(node* head)
   {
	if(head==) return;
	reverse_print_helper(head->next);
	printf("  %d",head->data);
    }
void reverse_print(node* last)
   {
       node * head = last->next;
       reverse_print_helper(head);
    }*/
node* create()
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
        head->next = NULL;
        last = head;
        for(i=2; i<=n; i++)
        {
            newNode = (node *)malloc(sizeof(node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->next = NULL;

            last->next = newNode; // Link previous node with the new node
            last = newNode; // Make new node as last node
        }
        last->next = head;

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
        return last;
    }
}
void size(struct node* last)
{
    node * head = last->next;
    int i =0;
    while(head!=)
	{
	    head = head->next;
		i++;
	}
	printf("%d",i);
}

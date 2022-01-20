#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
struct node
    {
        int num;
        struct node *link;
    };

struct node* head = NULL;
typedef struct node NODE;
struct node* create_list()
{
    int check;

    NODE  *first, *temp = 0;
    int count = 0;
    int choice = 1;
    first = 0;
    while (choice)
    {
        head  = (NODE *)malloc(sizeof(NODE));
        printf("Enter the num item\n");
        scanf("%d", &head-> num);
        if (first != 0)
        {
            temp->link = head;
            temp = head;
        }
        else
        {
            first = temp = head;
        }
        fflush(stdin);
        printf("Do you want to continue(Type 0 or 1)?\n");
        scanf("%d", &choice);
    }
    printf("%d",choice);
    temp->link = 0;
    temp = first;
    printf("\nStatus of the linked list is\n");
    while (temp != 0)
    {
        printf("%d=>", temp->num);
        count++;
        temp = temp -> link;
    }
    printf("NULL\n");
    printf("No. of nodes in the list = %d\n", count);
    return head;
}
void is_empty()
{
    if(head==NULL)
    {
        printf("Empty");
    }
    else {printf("Not Empty.");}
}
void is_last(struct node* head)
{
    if(head->link==NULL) {printf("Last node");}
    else{printf("Not Last node");}
}
struct node* insert_front(struct node* head,int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->num = x;
    temp->link = NULL;
	if(head!=NULL) temp->link = head;
	head = temp;
}
void insert(int num,int position)
{
	int i;
	struct node* temp1 = (struct node*)malloc(sizeof(struct node*));
	temp1->num=num;
	temp1->link = NULL;
	if(position==1)
	{
		temp1->link = head;

		head = temp1;
		return;
	}
	struct node* temp2 = head;
	for(i=0;i<position-2;i++)
	{
		temp2= temp2->link;
	}
	temp1->link =temp2->link;
	temp2->link = temp1;
}
struct node* delete_front(struct node* head)
{
    int n=1;
	int i;
	struct node* temp1 = head;
	if(n==1)
	{
		head=head->link;
		return head;
	}
	for(i=0;i<n-2;i++)
	{
		temp1 = temp1->link;
	}
	struct node* temp2 = temp1->link;
	temp1->link=temp2->link;
	free(temp2);
	return head;
}
void print(struct node* head)
{
	struct node *temp = head;
	printf("List is :\n");
	while(temp!=NULL)
	{
		printf("  %d",temp->num);
		temp = temp->link;
	}
	printf("\n");

}


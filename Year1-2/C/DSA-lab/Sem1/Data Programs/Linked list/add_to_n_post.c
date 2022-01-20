#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* head;

void print()
{
	struct node *temp = head;
//	printf("List is :\n");
	while(temp!=NULL)
	{
		printf("  %d",temp->data);
		temp = temp->link;
	}
	printf("\n");
}
void insert(int data,int position)
{
	int i;
	struct node* temp1 = (struct node*)malloc(sizeof(struct node*));
	temp1->data=data;
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
int main()
{
	head = NULL;
	insert(2,1); //list 2
	insert(3,2); //
	insert(4,1);
	insert(5,2);  
	print();
}

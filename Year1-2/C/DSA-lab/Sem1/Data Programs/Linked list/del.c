#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
struct Node* head;
void insert(int x)
{
	struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
//	*(temp).data = x;
    temp->data = x;
    temp->next = NULL;
  //  temp->next = head;
//	*(temp).next = NULL;
	if(head!=NULL) temp->next = head;
	head = temp;
//  temp-> = x;
}
void print()
{
	struct Node *temp = head;
	printf("List is :\n");
	while(temp!=NULL)
	{
		printf("  %d",temp->data);
		temp = temp->next;
	}
	printf("\n");
	
}
void delete(int n)
{
	int i;
	struct node* temp1 = head;
	while(temp1->!=)
}
int main()
{
	head==NULL;  //list is empty
	printf("Enter no. of number do you want :\n");
	int i,n,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the number :\n");
		scanf("%d",&x);
		insert(x);
		print();
	}
	return 0;
}

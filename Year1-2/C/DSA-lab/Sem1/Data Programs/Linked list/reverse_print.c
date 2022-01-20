#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
struct node* insert(struct node* head,int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
//	*(temp).data = x;
    temp->data = x;
    temp->link = NULL;
  //  temp->link = head;
//	*(temp).link = NULL;
	if(head!=NULL) temp->link = head;
	head = temp;
//  temp-> = x;
    return head;
}
void reverseprint(struct node* head)
{
	if(head==NULL) return;
	reverseprint(head->link);
	printf("%d",head->data);	
}
int main()
{
	struct node* head;
	head=NULL;
	head = insert(head,2);
	head = insert(head,4);
	head = insert(head,5);
	head = insert(head,6);
	reverseprint(head);
	
}

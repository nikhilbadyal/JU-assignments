#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* link;
};
//struct node* head;
struct node* insert(struct node* head,int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node*));
	temp->data = x;
	temp->link = NULL;
	if(head!=NULL) temp->link = head;
	head = temp;
	return head; 
}
void print(struct node* temp)
{
//	struct node* temp = head;
	printf("List is :\n");
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}
int main()
{
	struct node* head = NULL;
	printf("How many numbers do you want to enter :\n");
	int n,i,x;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the number : \n");
		scanf("%d",&x);
		head = insert(head,x);
		print(head);
	}
	return 0;
}

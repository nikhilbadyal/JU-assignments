#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* link;
};
//struct node* head;
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
struct node* reverse(struct node* head)
{
	struct node  *current,*next,*previous;
	previous = NULL;
	current = head;
	while(current!=NULL)
	{
		next=current->link;
		current->link=previous;
		previous = current;
		current = next;
	}
	head=previous;
	return head;
}
void print(struct node* head)
{
	struct node *temp = head;
	printf("List is :\n");
	while(temp!=NULL)
	{
		printf("  %d",temp->data);
		temp = temp->link;
	}
	printf("\n");
	
}
/*void delete(int n)
{
	int i;
	struct node* temp1 = head;
	if(n==1)
	{
		head=temp1->link;
		free(temp1);
		return ;
	}
	for(i=0;i<n-2;i++)
	{
		temp1 = temp1->link;
	}
	struct node* temp2 = temp1->link;
	temp1->link=temp2->link;
	free(temp2);
}*/
int main()
{
	struct node* head;
//	int n;
	head=NULL;
	head = insert(head,2);
	head = insert(head,4);
	head = insert(head,5);
	head = insert(head,6);
	head = insert(head,2);
	head = insert(head,4);
	head = insert(head,5);
	head = insert(head,6);
	head = insert(head,2);
	head = insert(head,4);
	head = insert(head,5);
	head = insert(head,6);
//	print();
    print(head);
    head = reverse(head);
//	printf("Enter the poistion you want to delete :\n");
//	scanf("%d",&n);
	print(head);
//	delete(n);
//	print();
}

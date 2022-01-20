#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node* next;
};
typedef struct Node node;
node *head1,*head2;
node* insert(node* head,int x)
{
	node* temp = (node*)malloc(sizeof(node));
//	*(temp).data = x;
    temp->data = x;
    temp->next = NULL;
  //  temp->next = head;
//	*(temp).next = NULL;
	if(head!=NULL)
        temp->next = head;
	head = temp;
//  temp-> = x;
    return head;
}
void print(node* head)
{
	node *temp = head;
	printf("List is :\n");
	while(temp!=NULL)
	{
		printf("  %d",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
void subtract(node* head1,node* head2)
{


}
int main()
{
  //  printf("Enter data to create list.\n");
  //  head1 = create_list(head1);

    head1 = insert(head1,110);
	head1 = insert(head1,90);
	head1 = insert(head1,70);
	head1 = insert(head1,70);
	head1 = insert(head1,30);
	head1 = insert(head1,10);
	print(head1);


	head2 = insert(head2,100);
	head2 = insert(head2,3);
	head2 = insert(head2,56);
	head2 = insert(head2,25);
	print(head2);
	subtract(head1,head2);
	return 0;
}

#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node* next;
}*head1,*head2,*head3=NULL,*head4;
typedef struct node NODE;

struct node* insert(struct node* head,int x)
{
	struct node* temp = (struct node*)malloc(sizeof(struct node));
//	*(temp).data = x;
    temp->data = x;
    temp->next = NULL;
  //  temp->next = head;
//	*(temp).next = NULL;
	if(head!=NULL) temp->next = head;
	head = temp;
//  temp-> = x;
    return head;
}
void print_same(struct node* head)
{
	struct node *temp = head;
	printf("List is :\n");
	while(temp!=NULL)
	{
		printf("  %d",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
NODE *recursion(NODE *head) {
    NODE *temp1 = (NODE*)malloc(sizeof(NODE));
    NODE *temp2 = (NODE*)malloc(sizeof(NODE));

    if (head->next == NULL) {
        return head;
    }
    else {
        temp1 =recursion(head->next);
        temp2 =head->next;
        temp2->next = head;
        head->next = NULL;
    }
    return temp1;
};

int main()
{

    head3 = insert(head3,110);
	head3 = insert(head3,90);
	head3 = insert(head3,70);
	head3 = insert(head3,70);
	head3 = insert(head3,30);
	head3 = insert(head3,10);
	NODE* p=head3;



	head4 = insert(head4,100);
	head4 = insert(head4,60);
	head4 = insert(head4,40);
	head4 = insert(head4,20);
//	print_same(head3);
      head3 = recursion(head3);
    print_same(head3);

    return 0;
}

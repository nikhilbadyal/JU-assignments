#include<stdio.h>
#include<stdlib.h>
struct node{
int num;
struct node* link;
};
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
void reverseprint(struct node* head)
   {
	if(head==NULL) return;
	reverseprint(head->link);
	printf("  %d",head->num);
    }
int main()
{
    int num;
    struct node* head = NULL;
    struct node* temp;
    FILE *fp;
    fp = fopen("list.txt","r");
    while(fscanf(fp,"%d",&num)!=EOF){
            if(head==NULL)
            {
                head = (struct node *)malloc(sizeof(struct node));
                head->num = num;
                head->link = NULL; // links the address field to NULL
                temp = head;
            }
            else{struct node* temp1 = (struct node *)malloc(sizeof(struct node));
            temp1->num = num;      // links the num field of fnNode with num
            temp1->link = NULL; // links the address field of fnNode with NULL

            temp->link = temp1; // links previous node i.e. tmp to the fnNode
            temp = temp->link;
            }

    }
    print(head);
    reverseprint(head);

}

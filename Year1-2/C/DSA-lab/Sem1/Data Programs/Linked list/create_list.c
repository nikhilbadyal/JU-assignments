#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;                        //Data of the node
    struct node *link;           //Address of the next node
};

struct node* createNodeList(int n); // function to create the list
void print(struct node*);         // function to display the list

struct node* create_list()
{
    struct node * temp;
    int n;
		printf("\n\n Linked List : To create and display Singly Linked List :\n");
		printf("-------------------------------------------------------------\n");

    printf(" Input the databer of nodes : ");
    scanf("%d", &n);
    temp = createNodeList(n);
    printf("\n Data entered in the list : \n");
    print(temp);
    return temp;
}
struct node* createNodeList(int n)
{
    struct node *fnNode, *tmp,*stnode;
    int data, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard

        printf(" Input data for node 1 : ");
        scanf("%d", &data);
        stnode->data = data;
        stnode->link = NULL; // links the address field to NULL
        tmp = stnode;
// Creating n nodes and adding to linked list
        for(i=2; i<=n; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input data for node %d : ", i);
                scanf(" %d", &data);

                fnNode->data = data;      // links the data field of fnNode with data
                fnNode->link = NULL; // links the address field of fnNode with NULL

                tmp->link = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->link;
            }
        }
    }
    return stnode;
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
void delete(struct node* head,int n)
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
	printf("\n");
	print(head);
}


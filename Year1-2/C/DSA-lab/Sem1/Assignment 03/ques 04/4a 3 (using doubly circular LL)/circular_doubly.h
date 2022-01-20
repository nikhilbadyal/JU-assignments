#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};struct Node *head1,*last,*head2,*head,*head3;
typedef struct Node node;
node * GetNewNode(int x)
{
    node* NewNode= (node *)malloc(sizeof(node));
    NewNode->data = x;
    NewNode->prev=NULL;
    NewNode->next=NULL;
    return NewNode;
}
void create()
{
    int n;
    printf("How many nodes do you want.\n");
    scanf("%d",&n);
    int i, data;
    node *newNode;

    if(n >= 1)
    {
        head = (node *)malloc(sizeof(node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;
        last = head;
        for(i=2; i<=n; i++)
        {
            newNode = (node *)malloc(sizeof(node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; // Link new node with the previous node
            newNode->next = NULL;

            last->next = newNode; // Link previous node with the new node
            last = newNode; // Make new node as last node
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

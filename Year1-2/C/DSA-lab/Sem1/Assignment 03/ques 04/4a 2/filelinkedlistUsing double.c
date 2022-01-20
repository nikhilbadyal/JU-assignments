#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};struct Node *head,*last;
typedef struct Node node;
struct Node * GetNewNode(int x)
{
    struct Node* NewNode= (struct Node *)malloc(sizeof(struct Node));
    NewNode->data = x;
    NewNode->prev=NULL;
    NewNode->next=NULL;
    return NewNode;
}
bool check_empty(struct Node* head)
{
    if(head==NULL)
        return true;
    return false;
}
void Print(node* head)
{
   int check = check_empty(head);
    if(check != 1)
    {
        struct Node * temp = head;
        printf("List is : \n");
        while(temp!= NULL)
        {
        printf(" %d",temp->data);
        temp = temp->next;
        }
        printf("\n");
    }
}
void ReversePrint()
{
    struct Node *temp = head;
    if(temp==NULL) return ;
    while(temp->next!=NULL) {temp=temp->next;}
    printf("Reversed list is:\n");
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->prev;
    }
    printf("\n");
}
node*  InsertAtHead(node* head,int x)
{
    struct Node * fnode = GetNewNode(x);
    if(head==NULL)
    {
        head = fnode;
        return head;
    }
    head->prev = fnode;
    fnode->next = head;
    head = fnode;
    return head;
}
node*  InsertAtTail(node* head,int x)
{
    struct Node * lnode = GetNewNode(x);
    if(head==NULL)
    {
        head = lnode;
        return head;
    }
    struct Node * temp = head;
    while(temp->next!=NULL) {temp=temp->next;}
    temp->next = lnode;
    lnode->prev = temp;
    return head;
}
int main()
{
    int num;
    head = NULL;
    struct node* temp;
    FILE *fp;
    fp = fopen("list.txt","r");
    while(fscanf(fp,"%d",&num)!=EOF){
            if(head==NULL)
            {
                head = InsertAtHead(head,num);
            }
            else{
                    head = InsertAtTail(head , num);
            }

    }
    Print(head);
    ReversePrint(head);

}


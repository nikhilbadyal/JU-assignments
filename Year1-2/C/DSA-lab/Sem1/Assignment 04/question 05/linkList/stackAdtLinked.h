#include<stdlib.h>
#include<stdexcept>
struct Stack{
    int data;
    struct Stack * next ;
};
typedef struct Stack Stack;
void push(Stack ** , int );
void  pop(Stack **);
int peek(Stack **);
void display(Stack **);
void push(Stack **s , int value)
{
    Stack *temp = (Stack * ) malloc(sizeof(Stack));
    temp->data = value;
    temp->next = nullptr;
    if(*s != nullptr)
    {
        temp->next = *s;
    }
    *s = temp;
    //return s ;
}
void pop(Stack **s)
{
    if(s == nullptr)
    {
        printf("Under flow \n");
        return ;
    }
    Stack *temp = *s;
    *s = (*s)->next ;
    free(temp);
}
int peek(Stack **s )
{
    if(s == nullptr)
    {
        printf("Under flow \n");
        return -1;
    }
    return (*s)->data;

}
void display(Stack **s)
{
    if(*s== NULL)
    {
        printf("Stack empty.");
        return ;
    }
    Stack * temp = *s;
    while(temp!= NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next ;
    }
    return ;
}
void displayRev(Stack** head)
{
    if(*head==NULL) return;
    displayRev(&(*head)->next);
    printf("  %d",(*head)->data);
    return ;
}/*
void displayRevDelete(Stack** head)
{
    if(*head==NULL) return;
    displayRev(&(*head)->next);
    printf("  %d",(*head)->data);
    free(*head);
    return ;
}*/
bool equality(Stack **head1, Stack **head2)
{
    Stack * temp1 = * head1;
    Stack * temp2 = *head2;
    while(temp1 !=NULL && temp2!= NULL)
	{
	    if(temp1->data!= temp2->data){ return false;}
	    temp1 = temp1->next;
	    temp2 = temp2->next;
	}
	return (temp1 ==NULL && temp2 == NULL);
}

#include <stdio.h>
#include <stdlib.h>

#define TRUE  1
#define FALSE 0

typedefstructnodetag{
    float val;
structnodetag* next;
}node;

void init_l(node* head){
    head = NULL;
    return;
}

intempty_l(node* head){
if(head == NULL) return TRUE;
    else return FALSE;
}

intatend_l(node* tail){
    if(tail->next == NULL) return TRUE;
    else return FALSE;
}

void insert_front(node* target, node** head){
    target->next = *head;
    (*head) = target;
}

void insert_after(node* target, node* prev){
    target->next = prev->next;
prev->next   = target;
}

void delete_front(node** head){
    node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

void delete_after(node* prev){
    node* temp = prev->next;
prev->next = temp->next;
    free(temp);
}

node* create(float var){
    node* temp = (node*)malloc(sizeof(node));
    temp->next = NULL;
    temp->val  =var;
    return temp;
}

void print_l(node* head){
    node* temp = head;
printf("\n");
while(temp != NULL){
printf("%f<->",temp->val);
        temp = temp->next;
    }
printf("\n");
}

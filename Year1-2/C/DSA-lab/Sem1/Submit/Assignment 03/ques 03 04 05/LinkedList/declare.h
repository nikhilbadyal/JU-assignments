#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
int data;
struct node* next;
}*temp1,*temp,*head;
typedef struct node NODE;

struct node* create_list(struct node* head);
void print_same(struct node* head);
void reverse_print(struct node* head);
void size(struct node* head);
bool equality(struct node*head1,struct node*head2);
bool search_sorted(struct node* head, int x);
void split(NODE* source, NODE** frontsp, NODE** backsp);
NODE * merge_sorted(NODE * headd1, NODE* headd2);
NODE * merge_sort(NODE * head);
bool search_unsorted(NODE* head, int x);
void append_list(NODE* head1,struct node* head2);
NODE* delete_nth(NODE* head,int n);
struct node* delete_front(struct node* head);
struct node* delete_last(struct node* head);
bool ascend(struct node* head);
bool descend(struct node * head);
bool is_sorted(struct node* head);
struct node* insert_front(struct node* head,int x);
NODE* insert_n(NODE* head,int data,int position);
NODE * insertAtEnd(NODE* head1,int x);
NODE * remove_dup(NODE * head);
NODE * moveLtoF(NODE * head);
NODE * del_alt(NODE * head);
NODE * moveFtoL(NODE * head);
NODE * rotate(NODE* head);
void  del_list(NODE* head);
struct node* recursion(struct node* head);
bool not_equal(struct node * head1,struct node * head2);
void deleteByValue(NODE * head , int value );

#include"declare.h"
struct node* create_list(struct node* head)
{
    int num,i;
    while(i)
    {
        printf("Enter data.\n");
        scanf("%d",&num);
        if(head==NULL)
        {
            head = (struct node *)malloc(sizeof(struct node));
            head->data = num;
            head->next = NULL; // nexts the address field to NULL
            temp = head;
        }
        else{struct node* temp1 = (struct node *)malloc(sizeof(struct node));
        temp1->data = num;      // nexts the num field of fnNode with num
        temp1->next = NULL; // nexts the address field of fnNode with NULL

        temp->next = temp1; // nexts previous node i.e. tmp to the fnNode
        temp = temp->next;
        }
        printf("Enter 1 to enter more.\n");
        scanf("%d",&i);
    }

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
void reverse_print(struct node* head)
   {
	if(head==NULL) return;
	reverse_print(head->next);
	printf("  %d",head->data);
	return ;
    }
void size(struct node* head)
{
    int i =0;
    while(head!=NULL)
	{
	    head = head->next;
		i++;
	}
	printf("%d",i);
}
bool equality(struct node*head1,struct node*head2)
{
    int flag =0;
    while(head1!=NULL && head2!= NULL)
	{
	    if(head1->data!=head2->data){ return false;}
	    head1 = head1->next;
	    head2 = head2->next;
	}
	return (head1 ==NULL && head2 == NULL);
}
bool search_sorted(struct node* head, int x)
{
    struct node* current = head;  // Initialize current
    while (current != NULL)
    {
        if (current->data == x)
            return true;
        current = current->next;
    }
    return false;
}
void split(NODE* source, NODE** frontsp, NODE** backsp)
{
    NODE* fast;
    NODE* slow;
    slow = source;
    fast = source->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *frontsp = source;
    *backsp = slow->next;
    slow->next = NULL;
}
NODE * merge_sorted(NODE * headd1, NODE* headd2)
{
    NODE *s;
    NODE *new_head=NULL;
    if(headd1->data>=headd2->data)
    {
       s = headd2;
        headd2 = s->next;
    }
    else{
             s = headd1;
        headd1 = s->next;
        }
    new_head = s;

    while(headd1!=NULL && headd2!=NULL)
    {
        if(headd1->data>=headd2->data)  //big
        {
            s->next= headd2;
            s = headd2;
            headd2 = headd2->next;
        }
        else  {//small
                s->next = headd1;    // s->next = head2;
            s = headd1;   // s = head2;
            headd1 = headd1->next;

    }
    }
    if(headd1==NULL) s->next = headd2;
    if(headd2==NULL) s->next = headd1;
 //  print_same(new_head);
    return new_head;
}
NODE * merge_sort(NODE * head)
{
    NODE * temp = head;
    NODE * a ;
    NODE * b;

    if ((temp == NULL) || (temp->next == NULL)) {
        return head;}
    split(head,&a,&b);
    a = merge_sort(a);
    b = merge_sort(b);
    head = merge_sorted(a,b);
    return head;
}
bool search_unsorted(NODE* head, int x)
{
    head = merge_sort(head);
    return search_sorted(head,x);
}
void append_list(NODE* head1,struct node* head2)
{
    NODE *temp=head1;
    while(temp->next!=NULL) {temp = temp->next;}
    temp->next = head2;
    print_same(head1);
}
NODE* delete_nth(NODE* head,int n)
{
	int i;
	NODE* temp1 = head;
	if(n==1)
	{
		head=head->next;
		return head;
	}
	for(i=0;i<n-2;i++)
	{
		temp1 = temp1->next;
	}
	NODE* temp2 = temp1->next;
	temp1->next=temp2->next;
	free(temp2);
	return head;
}
struct node* delete_front(struct node* head)
{
		head=head->next;
		return head;
}
struct node* delete_last(struct node* head)
{
	int i;
	struct node* temp1 = head;
	while(temp1->next->next!=NULL)
	{
		temp1 = temp1->next;
	}
	struct node* temp2 = temp1->next;
	temp1->next=temp2->next;
	free(temp2);
	return head;
}
bool ascend(struct node* head){
    while(head!=NULL && head->next != NULL)
    {
        if(head->data>head->next->data) {return true;} //NOt Ascend
        head = head->next;
    }

}
bool descend(struct node * head){
    while(head!=NULL && head->next != NULL)
    {
        if(head->data<head->next->data) {return true;} //NOt DEScend
        head = head->next;
    }

}
bool is_sorted(struct node* head)
{
    int i;
    if(ascend(head))
    { if(descend(head))
       {
        printf("Array unordered.\n");
        }
        else{printf("Array in Descending order.");}
    }
    else{
        printf("Array in Ascending order.");
    }
}
struct node* insert_front(struct node* head,int x)
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
NODE* insert_n(NODE* head,int data,int position)
{
	int i;
	NODE* temp1 = (NODE*)malloc(sizeof(NODE));
	temp1->data=data;
	temp1->next = NULL;
	if(position==1)
	{
		temp1->next = head;

		head = temp1;
		return head;
	}
	NODE* temp2 = head;
	for(i=0;i<position-2;i++)
	{
		temp2= temp2->next;
	}
	temp1->next =temp2->next;
	//if(temp2->next == NULL)// printf("yes");
	temp2->next = temp1;
//	if(temp1->next == NULL)// printf("not");
	return (head);
}
NODE * insertAtEnd(NODE* head1,int x)
{
    NODE * temp1= head1;
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->data = x;
	temp->next = NULL;
	while(temp1->next!=NULL)
    {
       temp1= temp1->next;
    }
    temp1->next = temp;
    return (head1);

}
NODE * remove_dup(NODE * head)
{
    if(head == NULL) { printf("List Empty."); return head; }
    NODE * temp = head;
    NODE *temp1 = NULL;
    while(temp->next !=NULL)
    {
        if(temp->data == temp->next->data)
        {
            temp1 = temp->next->next;
            free(temp->next);
            temp->next = temp1;
        }
        else{

            temp = temp->next;
        }
    }
    print_same(head);
    return head;
}
NODE * moveLtoF(NODE * head)
{
    NODE * temp1= head;
    NODE * temp2= head->next;
    NODE * temp3 = head;
    while(temp2->next!=NULL)
    {
        temp2= temp2->next;
        temp1= temp1->next;
    }
    head = temp2;
    temp2->next = temp3;
    temp1->next =  NULL;
    print_same(head);
    return head;
}
NODE * del_alt(NODE * head)
{
    NODE *temp = head;
    NODE *temp1 = head->next;
    while(temp!=NULL && temp1!=NULL)
    {
        temp->next = temp1->next;
        free(temp1);

        temp= temp->next;
        if(temp!=NULL)
        {
            temp1= temp->next;
        }
    }
    return head;
}
NODE * moveFtoL(NODE * head)
{
    NODE * temp1 = head;
    NODE * temp2 = head->next;
    while(temp1->next!=NULL)
    {
        temp1= temp1->next;

    }
    temp1->next = head;
    head = temp2;
    temp1->next->next =NULL;
    return head;
}
NODE * rotate(NODE* head)
{
    int n,i;
    printf("Enter key value:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head = moveFtoL(head);
    }
    print_same(head);
}
void  del_list(NODE* head)
{
    if(head==NULL) return ;
	del_list(head->next);
	free(head);
	printf("List deleted.");

}/*
NODE *recursion(NODE *head) {
    NODE *temp1 = (NODE*)malloc(sizeof(NODE));
    NODE *temp2 = (NODE*)malloc(sizeof(NODE));

    if (head->next   == NULL) {
        return head;
    }
    else {
        temp1 =recursion(head->next);
        temp2 =head->next;
        temp2->next = head;
        head->next = NULL;
    }
    return temp1;
};*/
struct node* recursion(struct node* head){
    if(head->next == NULL){

        return head;
    }
    struct node* newHead = recursion(head->next);
    head->next->next = head;
    head->next = NULL;

    return newHead;
}
bool not_equal(struct node * head1,struct node * head2)
{
    return !equality(head1,head2);
}
void deleteByValue(NODE * head , int value )
{
    print_same(head);
    NODE * temp= head;
    while(temp->next->data != value)
    {
        temp = temp->next;
    }
    NODE * temp2 = temp->next;
    temp->next = temp2->next;
    free(temp2);
    print_same(head);
}

/*
NODE* insert_beg(NODE* head,int x)
{
	NODE* temp = (NODE*)malloc(sizeof(NODE));
	temp->data = x;
	temp->next = NULL;
	if(head!=NULL) temp->next = head;
	head = temp;
	print_same(head);
	return head;
}

NODE* delete(NODE* head,int n)
{
   // n=1;
	int i;
	NODE* temp1 = head;
	if(n==1)
	{
		head=head->next;
		return head;
	}
	for(i=0;i<n-2;i++)
	{
		temp1 = temp1->next;
	}

	NODE* temp2 = temp1->next;
	temp1->next=temp2->next;
	free(temp2);
	return head;
}*/

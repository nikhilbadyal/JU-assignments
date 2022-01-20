#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
	node* head = NULL;
	insert_beg(&head,4);
	display(head);
	insert_beg(&head,44);
	display(head);
	insert_beg(&head,444);
	display(head);
	insert_beg(&head,4444);
	display(head);
	insert_p(&head,5,1);
	display(head);
	insert_p(&head,55,3);
	display(head);
	append(&head,8);
	display(head);
	append(&head,88);
	display(head);
	dlt_f(&head);
	display(head);
	dlt_f(&head);
	display(head);
	dlt(&head,2);
	append(&head,56);
	append(&head,52);
	dlt(&head,3);
	display(head);
	
}

typedef struct nodetype{
	int data;
	struct nodetype* link;
}node;

void insert_beg(node **head,int data){
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->link = *head;
	*head = temp;
}

void display(node* head){
	node *temp = head;
	while(temp!=NULL) {
		printf("%d ",temp->data);
		temp = temp->link;
	}
	printf("\n");
}

void insert_p(node **head,int data, int pos){
	int i;	
	node *t = *head;	
	node *temp = (node*)malloc(sizeof(node));
	temp->data = data;temp->link = NULL;
	if(pos == 1){
		temp->link = *head;
		*head  = temp;
		return ;
	}
	for(i=0; i<pos-2; i++) t = t->link;
	temp->link = t->link;
	t->link = temp;
}

void append(node **head,int data){
	if(*head  == NULL) return ;
	node *temp = *head;
	node *t = (node*)malloc(sizeof(node));
	t->data = data; t->link = NULL;
	while(temp->link!=NULL) temp = temp->link;
	temp->link = t;
}

void dlt_f(node **head){
	node *temp = *head;
	*head = temp->link;
	free(temp);
}

void dlt(node **head,int pos){
	node *temp = *head;
	int i;
	for(i=0; i<pos-2; i++) temp = temp->link;
	node *t = temp->link;
	temp->link = t->link;
	free(t);
}

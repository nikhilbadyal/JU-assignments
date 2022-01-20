#include<stdio.h>
#include<stdlib.h>
struct node{
	int row,column,value;
	struct node* link; 
};
int run= 1;
struct node* input_sparse()
{
	printf("\t\tSparse matrix %d\n",run);
	run++;
	struct node* head1=0;
	struct node* p1 = (struct node*)malloc(sizeof(struct node));
	int i,num1,num2;
//	printf("Enter data for sparse matrix :\n");
	do{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		int d=1;
		printf("Enter row,column and values of %d term\n",d);
		scanf("%d%d%d",&temp->row,&temp->column,&temp->value);
		temp->link=NULL;
		if(head1==NULL)
		{
			head1=temp;
			p1=temp;
		}
		else{
			p1->link=temp;
			p1=temp;
		}
		printf("Do you want one more term.\nEnter 1 to enter more.\n");
		scanf("%d",&i);
		if(i==0)
		{
			return head1;
		}
	}while(i==1);
}
void add(struct node* sparse1,struct node* sparse2)
{
	struct node *p1,*p2;
	p1= sparse1;
	p2 = sparse2;
	printf("\nMatrix after adding both matrix is :\n");
	printf("Row   Column   Value \n");
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->row ==p2->row && p1->column ==p2->column)
		{
			printf("%d      %d      %d\n",p1->row,p1->column,p1->value+p2->value);
			p1=p1->link;
			p2=p2->link;
		}
		else if(p1->row==p2->row)
		{
			if(p1->column>p2->column)
			{
				printf("%d      %d      %d\n",p2->row,p2->column,p2->value);
				p2=p2->link;
			}
			else{
				printf("%d      %d      %d\n",p1->row,p1->column,p1->value);
				p1=p1->link;
			}
			p1=p1->link;
		}
		else if(p1->row>p2->row)
		{
			printf("%d      %d      %d\n",p2->row,p2->column,p2->value);
			p2=p2->link;
		}
		else{
			printf("%d      %d      %d\n",p1->row,p1->column,p1->value);
			p1=p1->link;
		}
	}
	while(p1!=NULL)
	{
		printf("%d      %d      %d\n",p1->row,p1->column,p1->value);
		p1=p1->link;
	}
	while(p2!=NULL)
	{
		printf("%d      %d      %d\n",p2->row,p2->column,p2->value);
		p2=p2->link;
	}
}
int main()
{
//	printf("Please enter the size of matrix :\n");
	struct node *sparse1,*sparse2;
	sparse1=input_sparse();
	//print(sparse1);
	sparse2=input_sparse();
	add(sparse1,sparse2);
//	printf("%d",sparse1->value);
	return 0;
}

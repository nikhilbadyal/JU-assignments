#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coff,exp;
	struct node* link;
};
int run=1;
struct node* create_polynomial()
{
	printf("\t\tPolynomial %d\n",run);
	run++;
	struct node* head1=0;
	struct node* p1 = (struct node*)malloc(sizeof(struct node));
	int i,num1,num2;
	printf("Enter data for polynomial :\n");
	do{
		struct node* temp = (struct node*)malloc(sizeof(struct node));
		int d=1;
		printf("Enter coffecient and exponent of %d term\n",d);
		scanf("%d%d",&temp->coff,&temp->exp);
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
void print(struct node* poly1)
{
	struct node *p1;
	p1=poly1;
	while(p1!=NULL)
	{
		printf("%dx^%d",p1->coff,p1->exp);
		p1=p1->link;
	    if(p1!=NULL)
	    {
	    	printf("+");
		}
    }
}
void add(struct node* poly1,struct node* poly2)
{
	struct node *p1,*p2;
	p1= poly1;
	p2 = poly2;
	printf("\nPolynomial after adding both polynomial is :\n");
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->exp==p2->exp)
		{
			printf("%dx^%d",p1->coff+p2->coff,p1->exp);
			p1=p1->link;
			p2=p2->link;
		}
		else if(p1->exp>p2->exp)
		{
			printf("%dx^%d",p1->coff,p1->exp);
			p1=p1->link;
		}
		else{
			printf("%dx^%d",p2->coff,p2->exp);
			p2=p2->link;
		}
		if(p1!=NULL || p2!=NULL)
		{
			printf("+");
		}
	}
	while(p1!=NULL)
	{
		printf("%dx^%d",p1->coff,p1->exp);
		p1=p1->link;
		if(p1!=NULL)
		{
			printf("+");
		}
	}
	while(p2!=NULL)
	{
		printf("%dx^%d",p2->coff,p2->exp);
		p2=p2->link;
		if(p2!=NULL)
		{
			printf("+");
		}
	}

}
void subtract(struct node* poly1,struct node* poly2)
{
	struct node *p1,*p2;
	p1= poly1;
	p2 = poly2;
	printf("\nPolynomial after absolute Subtraction of oth polynomial is :\n");
	while(p1!=NULL && p2!=NULL)
	{
		if(p1->exp==p2->exp)
		{
			printf("%dx^%d",p1->coff-p2->coff,p1->exp);
			p1=p1->link;
			p2=p2->link;
		}
		else if(p1->exp>p2->exp)
		{
			printf("%dx^%d",p1->coff,p1->exp);
			p1=p1->link;
		}
		else{
			printf("%dx^%d",p2->coff,p2->exp);
			p2=p2->link;
		}
		if(p1!=NULL || p2!=NULL)
		{
			printf("+");
		}
	}
	while(p1!=NULL)
	{
		printf("%dx^%d",p1->coff,p1->exp);
		p1=p1->link;
		if(p1!=NULL)
		{
			printf("+");
		}
	}
	while(p2!=NULL)
	{
		printf("%dx^%d",p2->coff,p2->exp);
		p2=p2->link;
		if(p2!=NULL)
		{
			printf("+");
		}
	}

}
struct node* diff(struct node* poly1)
{
    static int run=1,count=1,temprun=1;
	struct node* temp2;
	struct node* temp1;
	struct node* temp;
	do{
		struct node* results = (struct node*)malloc(sizeof(struct node));
		results->coff = poly1->coff*poly1->exp;
		results->exp=(poly1->exp-1);
	 	if(temprun==1)
		{
		 	temp2 = results;
			temp1 = poly1;
			temprun++;
			temp=temp2;
		}
		if(run==1)
		{
			results->link=NULL;
			run++;
		}
		else{
			temp->link=results;
			results->link=NULL;
			temp=results;
	    }
		poly1=poly1->link;
		count++;
	}while(poly1!=NULL);
	return temp2;
}
int main()
{
	struct node *poly1,*poly2,*temp2,*temp3;
	poly1 = create_polynomial();
	poly2 = create_polynomial();
/*	printf("\nPolynomial 1 is :\n");
	print(poly1);
	printf("\nPolynomial 2 is :\n");
	print(poly2);*/
	add(poly1,poly2);
/*	subtract(poly1,poly2);
	temp2=diff(poly1);
	printf("\nDifferentiation of 1 polynomial is :\n");
	print(temp2);
	temp3=diff(poly2);
	printf("\nDifferentiation of 2 polynomial is :\n");
	print(temp3);*/
	return 0;
}

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int x;
	struct node *next;
};

void display(struct node *HEAD)
{
	struct node *temp=HEAD;
	while(temp != NULL)
	{
		printf("%d",temp->x);
		temp=temp->next;
	}
	
}
void swap(struct node **HEAD1,struct node **HEAD2)
{
	struct node *temp;
	temp=*HEAD1;
	*HEAD1=*HEAD2;
	*HEAD2=temp;
}
struct node *append(struct node *HEAD1,struct node *HEAD2)
{
	struct node *temp=HEAD1;
	while(temp->next != NULL)
	{
		temp=temp->next;
	}
	temp->next=HEAD2;
	return(HEAD1);
}

struct node *push_carry(struct node *HEAD,struct node *p,int *carry)
{
	int sum;
	if(HEAD == p->next)
	return;
	
	HEAD->next=push_carry(HEAD->next,p,carry);
	
	sum=HEAD->x + *carry;
    *carry=sum/10;
    sum=sum%10;
    HEAD->x=sum;
    return(HEAD);
}
struct node *last_carry(struct node *HEAD,int carry)
{
	struct node *n;
	n=(struct node *)malloc(sizeof(struct node));
	n->x=carry;
	n->next=HEAD;
	HEAD=n;
	return(HEAD);
}
struct node *add_same(struct node *HEAD1,struct node *HEAD2,int *carry)
{
	if(HEAD1==NULL)
	{
	    return;
	}
	int sum;
	struct node *result;
	result=(struct node*)malloc(sizeof(struct node));
	result->next=add_same(HEAD1->next,HEAD2->next,carry);
	
	sum=HEAD1->x + HEAD2->x + *carry;
	*carry=sum/10;
	sum=sum%10;
	
	result->x=sum;
	return(result);
}

struct node *add_list(struct node *HEAD1,struct node *HEAD2,int m,int n)
{
	int carry=0;
	if(HEAD1==NULL)
	{
        return(HEAD2);
	}
	if(HEAD2==NULL)
	{
		return(HEAD1);
	}
	struct node *result;
	if(m == n)
	{
		result=add_same(HEAD1,HEAD2,&carry);
		if(carry != 0)
		{
		    result=last_carry(result,carry);
		}
		return(result);
	}
	if(m != n)
	{
		int diff;
		diff= m-n;
		if(diff<0)
		{
			diff= -diff;
			swap(&HEAD1,&HEAD2);
		}
		int i;
		struct node *p=HEAD1;
		struct node *q=p->next;
		for(i=0;i<diff-1;i++)
		{
			p=p->next;
			q=q->next;
		}
		p->next=NULL;
		
		result=add_same(q,HEAD2,&carry);
		result=append(HEAD1,result);
		struct node *temp=result;
		if(carry != 0)
		{
			result=push_carry(temp,p,&carry);
			
			if(carry != 0)
			{
				result=last_carry(result,carry);
			}
		}
		return(result);
	}
}

struct node *initalize(struct node *HEAD)
{
	struct node *temp=HEAD,*n;
	n=(struct node *)malloc(sizeof(struct node));
	scanf("%d",&(n->x));
	n->next=NULL;
	if(temp == NULL)
	{
		HEAD=n;
		return(HEAD);
	}
	while(temp->next != NULL)
	{
		temp=temp->next;
	}
	temp->next=n;
	return(HEAD);
}

int main()
{
	int m,n,i;
	struct node *HEAD1=NULL;
	struct node *HEAD2=NULL;
	struct node *result;
	printf("\nENTER TOTAL NUMBER OF DIGITS IS FIRST NUMBER : \n");
	scanf("%d",&m);
	printf("\nENTER TOTAL NUMBER OF DIGITS IS SECOND NUMBER : \n");
	scanf("%d",&n);
	printf("\nENTER THE DIGITS OF FIRST NUMBER ONE BY ONE : \n");
	for(i=0;i<m;i++)
	{
		HEAD1=initalize(HEAD1);
	}
	printf("\nENTER THE DIGITS OF SECOND NUMBER ONE BY ONE : \n");
	for(i=0;i<n;i++)
	{
		HEAD2=initalize(HEAD2);
	}
	
	result=add_list(HEAD1,HEAD2,m,n);
	display(result);
}

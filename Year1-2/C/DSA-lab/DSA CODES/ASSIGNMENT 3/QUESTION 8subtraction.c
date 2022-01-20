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

struct node *delete_beg(struct node *HEAD)
{
	struct node *temp=HEAD;
	HEAD=temp->next;
	free(temp);
	return(HEAD);
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
	int sub;
	if(HEAD == p->next)
	return;
	
	HEAD->next=push_carry(HEAD->next,p,carry);
	
	if(HEAD->x == 0)
	{
		sub=(10  -  *carry);
		*carry=1;
		HEAD->x=sub;
		return(HEAD);
	}
	else
	{
		sub=HEAD->x  -  *carry;
		*carry=0;
		HEAD->x=sub;
		return(HEAD);
	}
}
struct node *subtract_same(struct node *HEAD1,struct node *HEAD2,int *carry)
{
	if(HEAD1==NULL)
	{
	    return;
	}
	int sub;
	struct node *result;
	result=(struct node*)malloc(sizeof(struct node));
	result->next=subtract_same(HEAD1->next,HEAD2->next,carry);

	if((HEAD1->x - *carry)  <  HEAD2->x)
	{
		sub=(10+(HEAD1->x  -  *carry)) - (HEAD2->x);
		*carry=1;
		result->x=sub; 
		return(result);
	}
	if((HEAD1->x - *carry)  >=  HEAD2->x)
	{
		
		sub=(HEAD1->x - *carry)  - HEAD2->x;
    	*carry=0;
     	result->x=sub;
     	return(result);
	}
	
}

struct node *subtract_list(struct node *HEAD1,struct node *HEAD2,int m,int n)
{
	int carry=0,sign=1;
	if(HEAD1==NULL)
	{
        return(HEAD2);
	}
	if(HEAD2==NULL)
	{
		return(HEAD1);
	}
	struct node *result;
	if(HEAD1->x  <  HEAD2->x)
	{
			swap(&HEAD1,&HEAD2);
			sign=-1;
	}
	if(m == n)
	{
		result=subtract_same(HEAD1,HEAD2,&carry);
		result->x=result->x * sign;
		return(result);
	}
	if(m != n)
	{
		int diff;
		diff= m-n;
		
		if(diff<0)
		{
			diff= -diff;
			sign=-1;
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
		
		result=subtract_same(q,HEAD2,&carry); 
		result=append(HEAD1,result);
		struct node *temp=result;
		if(carry != 0)
		{
			result=push_carry(temp,p,&carry);
			temp=result;
			while(temp->x == 0)
			{
				result=delete_beg(result);
				temp=temp->next;
			}
		    result->x=result->x *sign;
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
	
	result=subtract_list(HEAD1,HEAD2,m,n);
	printf("\nResult is : ");
	display(result);
}

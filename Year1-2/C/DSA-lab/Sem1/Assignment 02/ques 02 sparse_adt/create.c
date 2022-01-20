#include<stdio.h>
#include<stdlib.h>
#define MAX 20
void readsparse(int b[MAX][3]);
void printsparse(int b[MAX][3]);
void create_sparse()
{
    int b1[MAX][3],b2[MAX][3];
    readsparse(b1);
    printsparse(b1);
}
void readsparse(int b[MAX][3])
{

int i,t,m,n;

printf("Enter no. of rows and columns:\n");

scanf("%d%d",&m,&n);
    printf("No. of non-zero triples:");

scanf("%d",&t);

b[0][0]=m;

b[0][1]=n;

b[0][2]=t;

for(i=1;i<=t;i++)
    {
printf("\nEnter the triples(row,column,value):\n");

scanf("%d%d%d",&b[i][0],&b[i][1],&b[i][2]);
    }
}
void printsparse(int b[MAX][3])
{

int i,t;

t=b[0][2];

printf("\nrow\tcolumn\tvalue");

for(i=1;i<=t;i++)
    {

printf("\n%d\t%d\t%d",b[i][0],b[i][1],b[i][2]);
    }
}


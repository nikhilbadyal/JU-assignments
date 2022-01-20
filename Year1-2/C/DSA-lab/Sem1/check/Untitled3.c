#include<stdio.h>
#define MAX 100

struct sparse_adt
{
  int arr[MAX][3];
};

struct sparse_adt add_sparse(struct sparse_adt s1,struct sparse_adt s2)
{
  int  i,j;
  int m=0,n=0;
  struct sparse_adt sum;
  sum.arr[0][0]=s1.arr[0][0];
  sum.arr[0][1]=s1.arr[0][1];
  sum.arr[0][2]=n;

  for(i=1;i<=4;i++)
  {

    if(s1.arr[i][0] == s2.arr[i][0])
    {
      for(j=0;s2.arr[i][j]==s2.arr[i+1][j];j++)
      {

      if(s1.arr[i][1] != s2.arr[i][1])
      {
        if(s1.arr[i][1] > s2.arr[i][1])
        {
          sum.arr[m][0]=s2.arr[m][0];
          sum.arr[m][1]=s2.arr[m][1];
          sum.arr[m][2]=s2.arr[m][2];
            m++;
            n++;
        }
        else
        {
          sum.arr[m][0]=s1.arr[m][0];
          sum.arr[m][1]=s1.arr[m][1];
          sum.arr[m][2]=s1.arr[m][2];
            m++;
            n++;
        }

      }

      else
      {
        sum.arr[m][0]=s1.arr[m][0];
        sum.arr[m][1]=s1.arr[m][1];
        sum.arr[m][2]=s1.arr[m][2]+s2.arr[m][2];
        m++;
        n++;
      }
    }
    }
      else
    {
         if(s1.arr[i][0] > s2.arr[i][0])
        {
          sum.arr[m][0]=s2.arr[m][0];
          sum.arr[m][1]=s2.arr[m][1];
          sum.arr[m][2]=s2.arr[m][2];
          m++;
             n++;
        }
      else
      {
         sum.arr[m][0]=s1.arr[m][0];
         sum.arr[m][1]=s1.arr[m][1];
          sum.arr[m][2]=s1.arr[m][2];
          m++;
          n++;
        }
       }
  return(sum);
}
}



struct sparse_adt get_matrix()
{
  int i,j;
  struct sparse_adt s;
  printf("Enter sparse matrix : \n");
  printf("Enter total number of rows : \n");
  scanf("%d",&s.arr[0][0]);
  printf("Enter total number of columns  : \n");
  scanf("%d",&s.arr[0][1]);
  printf("Enter the total number of elements : \n");
  scanf("%d",&s.arr[0][2]);
  for(i=1;i<=s.arr[0][2];i++)
  {
    printf("Enter row, column and value of %d element respectively : ",i);
    for(j=0;j<3;j++)
    {
      scanf("%d",&s.arr[i][j]);
    }
  }
  return(s);

}

void display(struct sparse_adt s)
{
  int  i,j;
  printf("Entered sparse matrix is : \n");
  for(i=0;i<=s.arr[0][2];i++)
  {
    for(j=0;j<3;j++)
    {
      printf("%d  ",s.arr[i][j]);
    }
    printf("\n");
  }
}
int menu()
{
  int ch;

  printf("Press 1 to add two sparse matrix : \n");
  printf("Press 2  to subtract tw0 sparse matrix : \n");
  printf("Press 3 to transpose a sparse matrix : \n");
  printf("press 4 to display : \n");
  scanf("%d",&ch);
  return(ch);
}

int main()
{
  struct sparse_adt s1,s2,result;
  while(1)
  {
    switch(menu())
    {
      case 1:  s1=get_matrix();
               s2=get_matrix();
               display(s1);
               display(s2);
               result=add_sparse(s1,s2);
               display(result);
               break;
    }
  }
}

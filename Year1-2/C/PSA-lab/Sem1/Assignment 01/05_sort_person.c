#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int* age_list(int no)
{
  int* ages;
  ages = (int *)malloc(no*sizeof(int));
  return ages;
}

char** name_list(int no)
{
  char (*name)[31];
  name = (char **)malloc(no*31*sizeof(char));
  return name;
}

void sorting(int *age,char (*name)[31],int n)
{
  int i,j;

  for(i=0;i<n;i++)
  {
    for(j=i;j<n;j++)
    {
      if(*(age+i)>*(age+j))
      {
        int temp;
               temp=age[i];
              age[i]=age[j];
               age[j]=temp;
               
        
        char temp1[30];
              strcpy(temp1,name[i]);
              strcpy(name[i],name[j]);
              strcpy(name[j],temp1);
      }
    }
  }
  
}


void display(int *age,char (*name)[31],int n)
{
  int i;
  printf("In function");
  printf("\n\n");
  for(i=0; i<n; i++){
  printf("Age : %d\n", *(age+i));
    printf("Name : %s\n",name[i]);
  }
  
}

int main()
{
  int no;
  int i;
  
  int *age;
  age = age_list(no);
  
  char (*name)[31];
  name = name_list(no);
  
  printf("Enter the number of inputs :: \n");
  scanf("%d",&no);
  
  for(i=0; i<no; i++){
    printf("Enter age : ");
    scanf("%d", &age[i]);
    printf("Enter name : ");
    scanf("%s[^\n]", &name[i]);
  }
  
  sorting(age,name,no);
  display(age,name,no);
  
  return 0;
}

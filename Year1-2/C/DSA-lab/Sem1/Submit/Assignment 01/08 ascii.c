#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void ascii(char[]);
int main()
{
    char ASCII[15];
    printf("Enter the character : \n");
    gets(ASCII);
    printf("\nThe ASCII value of  entered name(%s): \n",ASCII);

    ascii(ASCII);
    return 0;
}
void ascii(char ASCII[])
{
    int i,mid,length,k,str11,str21,str_sum,div[10],lastans[100];
    char str[100],str1[50],str2[50],prime[100][100];
    FILE *fp,*fp1,*fp2;
    fp = fopen("ascii.txt","wt");

    for(i=0;ASCII[i]!='\0';i++)
    {

        printf("%d",ASCII[i]);
        fprintf(fp,"%d",ASCII[i]);
    }
    fclose(fp);
    printf("\n\n");
    fp1 = fopen("ascii.txt","r");
  if(fp==NULL)
  {
    printf("NOt found");
  }
  fgets(str,100,fp);
  length = strlen(str);
  mid=length/2;
  for(i = 0; i < mid; i++) {
        str1[i]= str[i];
    }

    for(i = mid, k = 0; i <= length; i++, k++)
  {
        str2[k]= str[i];
    }


    str11 = atoi(str1);
    str21 = atoi(str2);

    printf("\nDividing the number in two half: \n");

    printf("First half : %d\n",str11);
    printf("Second half : %d\n",str21);


    printf("\nSum after adding both the halves is : \n");
    str_sum = str11+str21;
    printf("%d\n",str_sum);

    fp2 = fopen("prime_numbers.txt","r");
    i=0;
    while(!feof(fp2))
    {
        fscanf(fp2,"%s",prime[i]);
        i++;
    }

    for(i=0;i<4;i++)
    {
      div[i]=atoi(prime[i]);
  }
  printf("\n");

  for(i=0;i<4;i++)
  {
    lastans[i]=str_sum%div[i];
  }
  for(i=0;i<4;i++)
  {
    printf("When %d is divided by %d ,remainder is : ",str_sum,div[i]);
    printf("%d\n",lastans[i]);
  }

}

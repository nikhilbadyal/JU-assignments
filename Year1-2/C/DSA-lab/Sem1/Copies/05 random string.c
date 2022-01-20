#include<stdio.h>
void random_string(int );
char alpha[26] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
FILE *fp;
int main()
{
    int n,j=1,k=0;
    
    fp = fopen("random_string.txt","wt");
    printf("How many random strings do you want :\n");
    scanf("%d",&n);

    for(j=1;j<=n;j++)
    {
        random_string(j);
        fprintf(fp,"\n");
        printf("\n");
    }
    fclose(fp);

}
void random_string(int x)
{
    int i,n1;
    char str[10];
    //fp = fopen("random_string.txt","wt");
    ;
    for(i=1;i<=10;i++)
    {
        n1 = rand()%25 + 1;
        //str[i]=alpha[n1];
        printf("%c",alpha[n1]);
        fprintf(fp,"%c",alpha[n1]);
   }
   
}

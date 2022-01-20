#include<stdio.h>
int main()
{
	FILE *fp;
	fp=fopen("audio.txt","w");
	int n,i,j;
	Char ch[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

	printf("Enter the number of string you want to print : ");
	scanf("%d",&n);
	
	i=0;
	srand();
	for(i=0;i<100000;i++)
	{
		for(j=0;j<10;j++)
		{
		  n=rand()%25 + 1;
	     	  printf("%c",ch[n]);
	        fprintf(fp,"%c",ch[n]);
	
		}
		printf("\n");
		fprintf(fp,"\n");
		
	}
	
	fclose(fp);
}

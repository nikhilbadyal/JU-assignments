#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
	char str[100000][10],alphanum[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	bool ar[10]={0};
	int i,j,k=0;
	FILE *fp;
	time_t t;
	srand((unsigned) time(&t));
	fp=fopen("FILE2","w");
	for(i=0;i<100000;i++)
	{
		for(j=0;j<10;j++)
		{
			str[i][j]=alphanum[rand() % (sizeof(alphanum) - 1)];
		}
j=0;k=0;
		while(str[j][] != ‘\0’)
		{
			if(!strcmp(str[j][],str[i][])
			{	k=1;break;}
			j++;
		}
		if(k==1)
			i--;
	}
	for(i=0;i<100000;i++)
	{
		for(j=0;j<10;j++)
		{
			fprintf(fp,"%c",str[i][j]);
		}
		fprintf(fp,"\n");
	}
	fclose(fp);
}

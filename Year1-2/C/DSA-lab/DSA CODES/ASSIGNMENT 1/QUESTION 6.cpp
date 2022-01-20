#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void display(char **names,int n)
{
	int i=0;
	printf("Data in ascending order\n");
	for(i=0;i<n;i++)
	{
		printf("Name : %s\n",names[i]);
	}
}
void sort(char ***names, int n)
{
	int i,j;
	char **name = (char**)malloc(n*sizeof(char *));
	for(i=0;i<n;i++)
		name[i]=(char *)malloc(40 * sizeof(char));
	name = *names;
	char temp[40]; int t;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(strcasecmp(name[j],name[j+1])>0)
			{
				strcpy(temp,name[j]);
				strcpy(name[j],name[j+1]);
				strcpy(name[j+1],temp);
			}
		}
	}
}
void main()
{
	int i,n;	
	int small=40,large=0;	
	char small1[40],large1[40];
	FILE *fp1,*fp2;
	char str1[100],str2;
	fp1=fopen("name.txt","w");
	printf("Enter the number of names ?");
	scanf("%d",&n);
	for(i=0;i<=n;i++)
	{
		fgets(str1,sizeof(str1),stdin);
		fputs(str1,fp1);
	}
	fclose(fp1);
	char **names;
	names = (char **)malloc(n*sizeof(char *));
	fp2=fopen("name.txt","r");
	str2=fgetc(fp2);
	int j=0;
	for(i=0;i<n;i++)
		names[i]=malloc(40*sizeof(char));
	i=0,j=0;	
	while(fgets(str1,sizeof(str1),fp2))
	{
		int n1=strlen(str1);
		if(n1>0 && str1[n1-1]=='\n')
			str1[n1-1]='\0';
		if(i>=n && n1>40)
			break;
		
		strcpy(names[i],str1);
		i++;
	}
	for(i=0;i<n;i++)
	{
		if(strlen(names[i])<small)
		{
			strcpy(small1,names[i]);
			small=strlen(names[i]);
		}
		if(strlen(names[i])>large)
		{
			strcpy(large1,names[i]);
			large=strlen(names[i]);
		}
	}	
	printf("The largest name : %s \n Length : %d \n The smallest name : %s \n Length : %d \n",large1,large,small1,small);
	sort(&names,n);
	fclose(fp2);
	FILE *fp3;
	fp3=fopen("sorted_names.txt","w");
	for(i=0;i<n;i++)
	{
		fprintf(fp3,"%s\n",names[i]);
	}
	fclose(fp3);
}	

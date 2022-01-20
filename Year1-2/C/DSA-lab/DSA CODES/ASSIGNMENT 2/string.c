#include <stdio.h>
#include "string.h"

int main(){
	char s[10],c,k,s1[10],s2[20],s3[10];
	int l,l1,l2 ;
	printf("Enter the string\n");
	scanf("%s",s);
	l = len(s);
	printf("Length = %d\n",l);
	fflush(stdin);
	printf("Enter the character to find it's number of occurence\n");
	c = getchar();
	l1 = nor(c,s);
	printf("Number of occurence = %d\n",l1);
	printf("Enter the character to find it's first occurence\n");
	fflush(stdin);scanf("%c",&k);
	l2 = first_f(k,s);
	printf("First occurence is at position %d\n",l2);
	printf("Now the source string is going to be copied to target string\n");
	fflush(stdin);xstrcpy(s1,s);
	display(s1);
	printf("Enter the string to concatenate\n");
	fflush(stdin);scanf("%s",s2);
	printf("After conactenation,the target string becomes:\n");
	fflush(stdin);xstrcat(s2,s);
	display(s2);
	printf("Enter the string to compare with the first string\n");
	fflush(stdin);scanf("%s",s3);
	printf("After comparing : %d\n",xstrcmp(s3,s1));

return 0;
}

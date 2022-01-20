#include <stdio.h>

int len(char *s){
	int i = 0,count = 0;
	while(*s!='\0') {count++;s++;}

return count;
}

int nor(char c,char *s){
	int count = 0;
	while(*s!='\0'){
		if(*s == c) count++;
		s++;
	}

return count;
}

int first_f(char c,char *s){
	int i,k,size;
	size = len(s);
	for(i=0; i<size; i++){
		if(s[i] == c) break;
	}
if(i == size) return -1;
return i;
}

void xstrcpy(char *t,char *s){
	while(*s!='\0'){
		*t = *s;
		t++;s++;
	}
	*t = '\0';
}

void xstrcat(char *t,char *s){
	int s1,s2,i,j;
	char a[20];
	s1 = len(t);
	s2 = len(s);
	for(i=0; i<s2; i++) a[i] = s[i];
	for(i=s2,j=0; i<s1+s2,j<s1; i++,j++) a[i] = t[j];
	xstrcpy(t,a);
	t[s1+s2] = '\0';

}

int xstrcmp(char *t,char *s){
	int l1,l2,i,k;
	l1 = len(t);
	l2 = len(s);
	k = (l1<=l2?l1:l2);
	for(i=0; i<k; i++){
		if(t[i] == s[i]) continue;
		else return (s[i] - t[i]);
	}
if(i == k){
	return 0;
}
	
}

void display(char *s){
	int i;
	while(*s!='\0') {printf("%c",*s); s++;}
	printf("\n");
}

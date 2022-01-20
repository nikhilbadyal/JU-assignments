#include <stdio.h>

void sort(int *a,int n){
	int i,j,temp;
	for(i=0; i<n; i++){
		for(j=i+1; j<n; j++){
			if(a[i]>a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

}

void final(int* a,int n){
	int i,j=0;
	for(i=0; i<n; i++){
		if(a[i]!=a[i+1]){
			a[j] = a[i];
			j++;
		}
	}
	if(a[n-2]!=a[n-1]) return;
	a[j] = a[n-1];

}

int lenght(int* a,int n){
	int i,j=0;
	for(i=0; i<n; i++){
		if(a[i] != a[i+1]) j++;
	}
return j;
}

void display(int *a,int len){
	int i;
	for(i=0; i<len; i++){
		printf("%d ",a[i]);
	}

	printf("\n");
}

int find(int *a,int n,int len){
	int i;
	for(i=0; i<len; i++) {
		if(a[i] == n) return i+1;
	}

	return 0;
}

void erase(int *a,int pos,int *len){
	int i;
	if(pos>*len) return ;
	for(i=pos; i<*len-1; i++){
		a[i] = a[i+1];
	}
	*len--;
}

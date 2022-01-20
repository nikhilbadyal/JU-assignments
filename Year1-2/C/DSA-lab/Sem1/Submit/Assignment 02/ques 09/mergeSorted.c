#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void insert(int a[],int n){
	int i;
	printf("Enter the elements\n");
	for(i=0; i<n; i++){
		scanf("%d",&a[i]);
	}

}

void sort(int a[],int n){
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

void copy(int a[],int b[],int c[],int m,int n){
	int i,k = 0;
	for(i=0; i<m; i++) c[k++] = a[i];
	for(i=0; i<n; i++) c[k++] = b[i];

}

void display(int a[],int n){
	int i;
	printf("The array after sorting is:\n");
	for(i=0; i<n; i++) printf("%d ",a[i]);

	printf("\n");

}

int main(){

	int s1,s2;
	printf("Enter the number of entries of the two arrays:\n");
	scanf("%d %d",&s1,&s2);
	int a[MAX],b[MAX],c[2*MAX];
	insert(a,s1);
	insert(b,s2);

	copy(a,b,c,s1,s2);

	sort(c,s1+s2);

	display(c,s1+s2);


	}


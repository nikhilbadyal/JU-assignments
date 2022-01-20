#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int* sorta(int a[],int n){
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
return a;
}

void compare(int a[],int b[],int n){
	int i,k1=0,k2=0;
	for(i=0; i<n; i++){
		if(a[i]!=b[i]){
			k1 = 1;
			break;
		}
	}

	for(i=0; i<n; i++){
		if(a[i]!=b[n-1-i]){
			k2 = 1;
			break;
		}
	}

	if(k1 == 1 && k2 == 1) printf("Not sorted.\n");
	if(k1 == 0 && k2 == 1) printf("Ascending Order Sorted.\n");
	if(k2 == 0 && k1 == 1) printf("Decending Order Sorted.\n");
	if(k1 == 0 && k2 == 0) printf("All the elements are same.\n");
}

int main(){

	int i,n,a[MAX],*b,c[MAX];
	int j;
	printf("Enter the number of elements :\n");
	scanf("%d",&n);
    j = 0;
	while(j<4){
            printf("Enter the elements:\n");
        for(i=0; i<n; i++) scanf("%d",&a[i]);
        for(i=0; i<n; i++) c[i] = a[i];

        b = sorta(c,n);


        compare(a,b,n);
        j++;
	}

}


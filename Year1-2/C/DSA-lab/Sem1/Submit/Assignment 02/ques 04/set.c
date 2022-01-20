#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int main(){
	int *a,n,i,size,m,key,d;
	printf("Enter the number of elements you want to enter\n");
	scanf("%d",&n);
	a = (int*)malloc(sizeof(int)*n);
	printf("Enter the elements.\n");
	for(i=0; i<n; i++){
		scanf("%d",a+i);
	}
	sort(a,n);
	final(a,n);
	size = lenght(a,n);
	printf("After converting the inputs into set, we get:\n");
	display(a,size);
	printf("Number of elements of the set = %d\n",size);
	printf("Enter the value you want to search for:\n");
	scanf("%d",&m);
	key = find(a,m,size);
	if(key) printf("Found!It is present at position %d\n",key);
	else printf("No element found\n");
	printf("Enter the position whose element you want to delete.\n");
	scanf("%d",&d);
	printf("After deleting ,the set is:\n");
	erase(a,d,&size);
	display(a,size-1);

return 0;

}

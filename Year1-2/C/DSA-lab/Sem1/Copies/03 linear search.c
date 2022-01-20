#include<stdio.h>
int main()
{
    int arr[100],x,i,n;

    printf("Enter number of elements in array\n");
    scanf("%d", &n);
 
    printf("Enter %d integer(s)\n", n);
 
    for (i = 0; i< n; i++)
        scanf("%d", &arr[i]);

    printf("Enter the element you want to search : \n");
    scanf("%d",&x);

    for(i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
        	printf("%d number is present at %d.",x,i+1);
            break;
		}
            
    }
    if(i==n)
    {
        printf("%d not present in array.",x);
    }
    return 0;
}

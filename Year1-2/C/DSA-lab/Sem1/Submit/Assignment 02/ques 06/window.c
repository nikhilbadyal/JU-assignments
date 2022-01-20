#include"window.h"
int main()
{
	int n,k,ch,c;
	printf("_______________________MENU_LIST_______________________\n");
	printf("Enter 1 for Maximum\nEnter 2 for Minimum\nEnter 3 for Median\nEnter 4 for Average\n\n");
	printf("Enter your choice : ");
	do
	{
		scanf("%d",&ch);
		printf("Enter length of array : ");
		scanf("%d",&n);
		printf("Enter size of sliding window : ");
		scanf("%d",&k);
		printf("Enter array elements : \n");
		for(int i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		switch(ch)
		{
			case 1:
				maximum(arr,n,k);
				break;
			case 2:
				minimum(arr,n,k);
				break;
			case 3:
				median(arr,n,k);
				break;
			case 4:
				average(arr,n,k);
				break;
			default:
				printf("Wrong Choice!\n");
		}
		display(op,(n-k+1));
		printf("\n");
		printf("\nDo you want to continue? Press 1 to continue : ");
		scanf("%d",&c);
	}while(c==1);
}

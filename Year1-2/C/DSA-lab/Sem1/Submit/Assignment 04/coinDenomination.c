// C program to find minimum number of denominations
#include <stdio.h>
#include<string.h>
#define MAX 20

// All denominations available.
int coins[5] = {1,5,10,25,50};

void findMin(int cost)
{
	char coinList[5] = {'0','0','0','0','0'};
	int i, k = 0;

	for (i = 4; i >= 0; i--) {
		while (cost >= coins[i]) {
			cost -= coins[i] ;
			coinList[i]++; // increment count of the particular coin in the list
		}
	}

	for (i = 0; i < 5; i++) {
	{
		printf("%d -> %c\n",coins[i],coinList[i]);
	}
	}
	return;
}

int main(void)
{
	int n;
	printf("Enter the amount in paise : ");
	scanf("%d",&n);
	printf("Following is the list of denomination with their respective  counts : \n");
	findMin(n);
	return 0;
}

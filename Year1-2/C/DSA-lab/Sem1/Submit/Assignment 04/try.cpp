// C program to Count
// Inversions in an array
#include <bits/stdc++.h>
int getInvCount(int arr[], int n)
{
	int inv_count = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (arr[i] > arr[j])
				inv_count++;

	return inv_count;
}

/* Driver progra to test above functions */
int main(int argv, char** args)
{
	int arr[] = {  11,999,9,193,7,6,5,300,3,2};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf(" Number of inversions are %d \n", getInvCount(arr, n));
	return 0;
}

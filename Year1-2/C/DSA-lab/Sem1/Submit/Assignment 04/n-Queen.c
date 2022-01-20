#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int ld[100] = { 0 };
int rd[100] = { 0 };
int cl[100] = { 0 };
/* A utility function to print solution */
void printSolution(int **board,int r)
{
	int i,j;
	for (i = 0; i < r; i++) {
		for (j = 0; j < r; j++)
			printf(" %d ", board[i][j]);
		printf("\n");
	}
}
bool solveNQUtil(int **board, int col,int r)
{
	int i;
	if (col >= r)
	return true;
	for (i = 0; i < r; i++) {
		if ((ld[i - col + r - 1] != 1 &&
				rd[i + col] != 1) && cl[i] != 1) {
			board[i][col] = 1;
			ld[i - col + r - 1] = rd[i + col] = cl[i] = 1;
			if (solveNQUtil(board, col + 1,r))
			return true;
			board[i][col] = 0; // BACKTRACK
			ld[i - col + r - 1] = rd[i + col] = cl[i] = 0;
		}
	}
	return false;
}
bool solveNQ(int **board,int r)
{
	if (solveNQUtil(board, 0,r) == false) {
	printf("Solution does not exist");
	return false;
	}
	printSolution(board,r);
	return true;
}
// driver program to test above function
int main()
{
	int **board;
	int r,i,j;
	printf("Enter rows: ");
	scanf("%d",&r);
	board=(int **)malloc(sizeof(int *)*r);
	for(i=0;i<r;i++)
		board[i]=(int *)malloc(sizeof(int)*r);
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
		{
			board[i][j] = 0;
		}
	}
	solveNQ(board,r);
	return 0;
}

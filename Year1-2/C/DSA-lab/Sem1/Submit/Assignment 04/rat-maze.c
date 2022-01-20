#include <stdio.h>
#include<stdlib.h>
int solveMazeUtil(int **maze, int x, int y, int **sol,int r,int c);
void printSolution(int **sol,int x,int y)
{
	int i,j;
	printf("\nThe required solution : \n");
	for (i = 0; i < x; i++) {
		for (j = 0; j < y; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}
int checkCell(int **maze, int x, int y,int r,int c)
{
	if (x >= 0 && x < r && y >= 0 && y < c && maze[x][y] == 1)
		return 1;
	return 0;
}
int solveMaze(int **maze,int **sol,int r,int c)
{
	if (!solveMazeUtil(maze, 0, 0, sol,r,c)) {
		printf("Solution doesn't exist");
		return 0;
	}
	return 1;
}
/* A recursive utility function to solve Maze problem */
int solveMazeUtil(int **maze, int x, int y, int **sol,int r,int c)
{
	if (x == r - 1 && y == c - 1) {
		sol[x][y] = 1;
		return 1;
	}
	if (checkCell(maze, x, y,r,c) == 1) {
		sol[x][y] = 1;
		if (solveMazeUtil(maze, x + 1, y, sol,r,c) == 1)
			return 1;
		if (solveMazeUtil(maze, x, y + 1, sol,r,c) == 1)
			return 1;
		sol[x][y] = 0;
		return 0;
	}
	return 0;
}
int main()
{
	int **maze,**sol;
	int r,c,i,j;
	printf("Enter rows and columns : ");
	scanf("%d %d",&r,&c);
	maze=(int **)malloc(sizeof(int *)*r);
	for(i=0;i<r;i++)
		maze[i]=(int *)malloc(sizeof(int)*c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("Enter element at position p[%d][%d] = ",i,j);
			scanf("%d",*(maze+i)+j);
		}
	}
	sol=(int **)malloc(sizeof(int *)*r);
	for(i=0;i<r;i++)
		sol[i]=(int *)malloc(sizeof(int)*c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			sol[i][j] = 0;
		}
	}
	if(solveMaze(maze,sol,r,c))
		printSolution(sol,r,c);
	return 0;
}

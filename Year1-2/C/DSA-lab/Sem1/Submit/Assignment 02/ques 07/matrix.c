#include<stdio.h>
#include<stdlib.h>
int dimensions()
{
	int r;
	printf("Enter the number of rows(cols same as rows) = ");
	scanf("%d",&r);
	return r;
}
int** dynamic_allocation(int r)
{
	int **p,i,j;
	p=(int **)malloc(sizeof(int*)*r);
	for(i=0;i<r;i++)
		p[i]=(int *)malloc(sizeof(int)*r);
	printf("Successful memory allocation\n");
	return p;
}
int** accept_values(int** p,int r)
{
	int i,j;
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
		{
			printf("Enter element at position p[%d][%d] = ",i,j);
			scanf("%d",*(p+i)+j);
		}
	}
	printf("Successful accepted value\n");
	return p;
}
int out_of_range(int i,int B_MAT_N){
    if(i<0 || i>=B_MAT_N) return 1;
    else return 0;
}
int** mul(int** n,int **m,int**p,int B_MAT_N,int S_MAT_N)
{
	printf("Inside mul\n");
	int row,col,s_col,val = 0,r_index;
	int s_mat_mid = (S_MAT_N-1)/2;
	for(row=0; row<B_MAT_N; row++){
        for(col=0; col<B_MAT_N; col++){
            val = 0;
            for(s_col=0; s_col<S_MAT_N;s_col++){
                r_index = row-s_mat_mid+s_col;
                if(!out_of_range(r_index,B_MAT_N))
                    val = val+n[r_index][col]*m[s_mat_mid][s_col];
            }
            p[row][col] = val;
            printf("%d \n",p[row][col]);
        }
    }
    return p;
}
/*void multiply(int mat[B_MAT_N][B_MAT_N], int sub_m[S_MAT_N][S_MAT_N], int out[B_MAT_N][B_MAT_N]){
    int s_mat_mid = (S_MAT_N-1)/2;
    printf("Mid = %d\n",s_mat_mid);
    for(int row=0; row<B_MAT_N; row++){
        for(int col=0; col<B_MAT_N; col++){
            int val = 0;
            for(int s_col=0; s_col<S_MAT_N;s_col++){
                int r_index = row-s_mat_mid+s_col;
                if(!out_of_range(r_index))
                    val = val+mat[r_index][col]*sub_m[s_mat_mid][s_col];
            }
            out[row][col] = val;
        }
    }
}*/
void print(int** p,int r)
{
	int i,j;
	printf("The matrix elements are = \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<r;j++)
			printf("%d ",*(*(p+i)+j));
		printf("\n");
	}
	printf("\n");
}
int main()
{
	int matrix_size,mask_width;
	int **n,**m,**p;
	matrix_size = dimensions();//matrix size
	mask_width = dimensions();//mask or kernel size;
	n = dynamic_allocation(matrix_size);
	m = dynamic_allocation(mask_width);
	p = dynamic_allocation(matrix_size);
	n = accept_values(n,matrix_size);
	m = accept_values(m,mask_width);
	p = mul(n,m,p,matrix_size,mask_width);
	print(n,matrix_size);
	print(m,mask_width);
	print(p,matrix_size);
	return 0;
}

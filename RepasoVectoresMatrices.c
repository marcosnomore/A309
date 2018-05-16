#include <stdio.h>
#include <stdlib.h>

#define N 3
#define M 3

int mat[N][M]={{3,4,2},{1,2,3},{4,5,6}};
int vect[N]={1,2,3};

void print_mat(int m[N][M])
{
	int i,j;
	for(i=0;i<N;i++)
	{
		for(j=0;j<M;j++)
			printf("%d ",mat[i][j]);
		puts("\n");
	}
}
void print_vec(int v[])
{
	int i;
	for(i=0; i<N; i++)
		printf("%d ", v[i]);
}

int main(void)
{
	print_mat(mat);
	print_vec(vect);
	return 0;
}

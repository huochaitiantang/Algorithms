#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
#define MAX 10

void print_matrix(int a[N][N]){
	int i,j;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return;
}

/* page 43: algorithm SQUARE MATRIX MULTIPLY
 * matrix multiply by violence
 * O(n^3)
 */
void multi_matrix(int a[N][N], int b[N][N], int c[N][N]){
	int i,j,k,cur;
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			cur = 0;
			for(k = 0; k < N; k++){
				cur += a[i][k] * b[k][j];
			}
			c[i][j] = cur;
		}
	}
	return;
}

int main(){
	int i,j,k;
	int a[N][N];
	int b[N][N];
	int c[N][N];
	clock_t t0,t1;
	srand((int)time(0));
	for(i = 0; i < N; i++){
		for(j = 0; j < N; j++){
			a[i][j] = rand() % MAX;
			b[i][j] = rand() % MAX;
		}
	}
	printf("Matrix A:\n");
	print_matrix(a);
	printf("Matrix B:\n");
	print_matrix(b);
	
	t0 = clock(); 
	multi_matrix(a, b, c);
	t1 = clock();
	printf("Matrix C=AxB(cost: %f ms):\n", (float)(t1-t0)/CLOCKS_PER_SEC*1000);
	print_matrix(c);

	return 0;
}

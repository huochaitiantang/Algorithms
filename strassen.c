#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define n 14
#define MAX 10

void print_matrix(int ** a, int lenth){
	int i,j;
	for(i = 0; i < lenth; i++){
		for(j = 0; j < lenth; j++){
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
void multi_matrix(int ** a, int ** b, int ** c, int lenth){
	int i,j,k,cur;
	for(i = 0; i < lenth; i++){
		for(j = 0; j < lenth; j++){
			cur = 0;
			for(k = 0; k < lenth; k++){
				cur += a[i][k] * b[k][j];
			}
			c[i][j] = cur;
		}
	}
	return;
}

void matrix_add(int ** a, int ** b, int ** c, int lenth){
	int i,j;
	for(i = 0; i < lenth; i++){
		for(j = 0; j < lenth; j++){
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	return;
}

void matrix_sub(int ** a, int ** b, int ** c, int lenth){
	int i,j;
	for(i = 0; i < lenth; i++){
		for(j = 0; j < lenth; j++){
			c[i][j] = a[i][j] - b[i][j];
		}
	}
	return;
}

/* page 45: algorithm strassen matrix multiply
 * O(n^lg7)
 */
void strassen_multi_matrix(int ** a, int ** b, int ** c, int lenth){
	int i,j,k,sublenth;
	int ** A11;
	int ** A12;
	int ** A21;
	int ** A22;
	int ** B11;
	int ** B12;
	int ** B21;
	int ** B22;
	int ** S1;
	int ** S2;
	int ** S3;
	int ** S4;
	int ** S5;
	int ** S6;
	int ** S7;
	int ** S8;
	int ** S9;
	int ** S10;
	int ** P1;
	int ** P2;
	int ** P3;
	int ** P4;
	int ** P5;
	int ** P6;
	int ** P7;
	int ** tmp1;
	int ** tmp2;
	if(lenth <= 1) {
		c[0][0] = a[0][0] * b[0][0];
		return;
	}
	sublenth = lenth / 2;
	A11 = (int *)malloc(sizeof(int *) * sublenth);
	A12 = (int *)malloc(sizeof(int *) * sublenth);
	A21 = (int *)malloc(sizeof(int *) * sublenth);
	A22 = (int *)malloc(sizeof(int *) * sublenth);
	B11 = (int *)malloc(sizeof(int *) * sublenth);
	B12 = (int *)malloc(sizeof(int *) * sublenth);
	B21 = (int *)malloc(sizeof(int *) * sublenth);
	B22 = (int *)malloc(sizeof(int *) * sublenth);
	S1 = (int *)malloc(sizeof(int *) * sublenth);
	S2 = (int *)malloc(sizeof(int *) * sublenth);
	S3 = (int *)malloc(sizeof(int *) * sublenth);
	S4 = (int *)malloc(sizeof(int *) * sublenth);
	S5 = (int *)malloc(sizeof(int *) * sublenth);
	S6 = (int *)malloc(sizeof(int *) * sublenth);
	S7 = (int *)malloc(sizeof(int *) * sublenth);
	S8 = (int *)malloc(sizeof(int *) * sublenth);
	S9 = (int *)malloc(sizeof(int *) * sublenth);
	S10 = (int *)malloc(sizeof(int *) * sublenth);
	P1 = (int *)malloc(sizeof(int *) * sublenth);
	P2 = (int *)malloc(sizeof(int *) * sublenth);
	P3 = (int *)malloc(sizeof(int *) * sublenth);
	P4 = (int *)malloc(sizeof(int *) * sublenth);
	P5 = (int *)malloc(sizeof(int *) * sublenth);
	P6 = (int *)malloc(sizeof(int *) * sublenth);
	P7 = (int *)malloc(sizeof(int *) * sublenth);
	tmp1 = (int *)malloc(sizeof(int *) * sublenth);
	tmp2 = (int *)malloc(sizeof(int *) * sublenth);
	for(i = 0; i < sublenth; i++){
		A11[i] = (int *)malloc(sizeof(int) * sublenth);
		A12[i] = (int *)malloc(sizeof(int) * sublenth);
		A21[i] = (int *)malloc(sizeof(int) * sublenth);
		A22[i] = (int *)malloc(sizeof(int) * sublenth);
		B11[i] = (int *)malloc(sizeof(int) * sublenth);
		B12[i] = (int *)malloc(sizeof(int) * sublenth);
		B21[i] = (int *)malloc(sizeof(int) * sublenth);
		B22[i] = (int *)malloc(sizeof(int) * sublenth);
		S1[i] = (int *)malloc(sizeof(int) * sublenth);
		S2[i] = (int *)malloc(sizeof(int) * sublenth);
		S3[i] = (int *)malloc(sizeof(int) * sublenth);
		S4[i] = (int *)malloc(sizeof(int) * sublenth);
		S5[i] = (int *)malloc(sizeof(int) * sublenth);
		S6[i] = (int *)malloc(sizeof(int) * sublenth);
		S7[i] = (int *)malloc(sizeof(int) * sublenth);
		S8[i] = (int *)malloc(sizeof(int) * sublenth);
		S9[i] = (int *)malloc(sizeof(int) * sublenth);
		S10[i] = (int *)malloc(sizeof(int) * sublenth);
		P1[i] = (int *)malloc(sizeof(int) * sublenth);
		P2[i] = (int *)malloc(sizeof(int) * sublenth);
		P3[i] = (int *)malloc(sizeof(int) * sublenth);
		P4[i] = (int *)malloc(sizeof(int) * sublenth);
		P5[i] = (int *)malloc(sizeof(int) * sublenth);
		P6[i] = (int *)malloc(sizeof(int) * sublenth);
		P7[i] = (int *)malloc(sizeof(int) * sublenth);
		tmp1[i] = (int *)malloc(sizeof(int) * sublenth);
		tmp2[i] = (int *)malloc(sizeof(int) * sublenth);
	}
	// A11, A12, A21, A22, B11, B12, B21, B22
	for(i = 0; i < sublenth; i++){
		for(j = 0; j < sublenth; j++){
			A11[i][j] = a[i][j];
			B11[i][j] = b[i][j];
			A12[i][j] = a[i][j + sublenth];
			B12[i][j] = b[i][j + sublenth];
			A21[i][j] = a[i + sublenth][j];
			B21[i][j] = b[i + sublenth][j];
			A22[i][j] = a[i + sublenth][j + sublenth];
			B22[i][j] = b[i + sublenth][j + sublenth];
		}
	}
	//S1-S10
	matrix_sub(B12, B22, S1, sublenth);
	matrix_add(A11, A12, S2, sublenth);
	matrix_add(A21, A22, S3, sublenth);
	matrix_sub(B21, B11, S4, sublenth);
	matrix_add(A11, A22, S5, sublenth);
	matrix_add(B11, B22, S6, sublenth);
	matrix_sub(A12, A22, S7, sublenth);
	matrix_add(B21, B22, S8, sublenth);
	matrix_sub(A11, A21, S9, sublenth);
	matrix_add(B11, B12, S10, sublenth);
	//P1-P7
	strassen_multi_matrix(A11, S1, P1, sublenth);
	strassen_multi_matrix(S2, B22, P2, sublenth);
	strassen_multi_matrix(S3, B11, P3, sublenth);
	strassen_multi_matrix(A22, S4, P4, sublenth);
	strassen_multi_matrix(S5, S6, P5, sublenth);
	strassen_multi_matrix(S7, S8, P6, sublenth);
	strassen_multi_matrix(S9, S10, P7, sublenth);
	// C11 = P5 + P4 - P2 + P6
	matrix_add(P5, P4, tmp1, sublenth);	
	matrix_sub(tmp1, P2, tmp2, sublenth);	
	matrix_add(tmp2, P6, tmp1, sublenth);
	for(i = 0; i < sublenth; i++){
		for(j = 0; j < sublenth; j++){
			c[i][j] = tmp1[i][j];
		}
	}
	// C12 = P1 + P2
	matrix_add(P1, P2, tmp1, sublenth);
	for(i = 0; i < sublenth; i++){
		for(j = 0; j < sublenth; j++){
			c[i][j + sublenth] = tmp1[i][j];
		}
	}	
	// C21 = P3 + P4
	matrix_add(P3, P4, tmp1, sublenth);
	for(i = 0; i < sublenth; i++){
		for(j = 0; j < sublenth; j++){
			c[i + sublenth][j] = tmp1[i][j];
		}
	}
	// C22 = P5 + P1 - P3 - P7
	matrix_add(P5, P1, tmp1, sublenth);	
	matrix_sub(tmp1, P3, tmp2, sublenth);	
	matrix_sub(tmp2, P7, tmp1, sublenth);	
	for(i = 0; i < sublenth; i++){
		for(j = 0; j < sublenth; j++){
			c[i + sublenth][j + sublenth] = tmp1[i][j];
		}
	}
	return;
}


int main(){
	int i,j,k;
	int ** a;
	int ** b;
	int ** c;
	int ** strassen_c;
	int N = n;
	float ind;
	int index;	
	clock_t t0,t1;
	srand((int)time(0));

	// pad n to 2^k
	ind = log((float)N) / log(2.);
	index = (int)ind;
	if(index < ind) index++;
	N = (int)pow(2, index);
	
	printf("n[%d] pad to N[%d]\n", n, N);

	a = (int *)malloc(sizeof(int *) * N);
	b = (int *)malloc(sizeof(int *) * N);
	c = (int *)malloc(sizeof(int *) * N);
	strassen_c = (int *)malloc(sizeof(int *) * N);
	for(i = 0; i < N; i++){
		a[i] = (int *)malloc(sizeof(int) * N);
		b[i] = (int *)malloc(sizeof(int) * N);
		c[i] = (int *)malloc(sizeof(int) * N);
		strassen_c[i] = (int *)malloc(sizeof(int) * N);
		for(j = 0; j < N; j++){
			if(i < n && j < n){
				a[i][j] = rand() % MAX;
				b[i][j] = rand() % MAX;
			}
			else{
				a[i][j] = 0;
				b[i][j] = 0;
			}

		}
	}
	printf("Matrix A:\n");
	print_matrix(a, N);
	printf("Matrix B:\n");
	print_matrix(b, N);
	
	t0 = clock(); 
	multi_matrix(a, b, c, N);
	t1 = clock();
	printf("Matrix C=AxB(violence cost: %f ms):\n", (float)(t1-t0)/CLOCKS_PER_SEC*1000);
	print_matrix(c, N);

	t0 = clock(); 
	strassen_multi_matrix(a, b, strassen_c, N);
	t1 = clock();
	printf("Matrix C=AxB(strassen cost: %f ms):\n", (float)(t1-t0)/CLOCKS_PER_SEC*1000);
	print_matrix(strassen_c, N);


	return 0;
}

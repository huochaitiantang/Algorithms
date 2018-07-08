#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100

/* page 12: practice 2.1-4
 * Given A = 100111010...111 (n bit)
 *       B = 010011100...110 (n bit)
 * Caculate C = A + B (n + 1 bit)
 */

void bit_add(int * a, int * b, int * c, int lenth){
	int i,x,tag=0;
	for(i = lenth - 1; i >= 0; i--){
		x = a[i] + b[i] + tag;
		c[i + 1] = x % 2;
		tag = x / 2;		
	}
	c[0] = tag;	
	return;
}

void printf_array(int * a, int lenth){
	int i;
	for(i = 0; i < lenth; i++){
		printf("%d", a[i]);
	}
	printf("\n");
	return;
}

int main(){
	int i;
	int * a;
	int * b;
	int * c;

	a = (int *)malloc(sizeof(int) * N);
	b = (int *)malloc(sizeof(int) * N);
	c = (int *)malloc(sizeof(int) * (N+1));

	srand((int)time(0));
	for(i = 0; i < N; i++){
		a[i] = rand() % 2;
		b[i] = rand() % 2;
	}

	bit_add(a, b, c, N);
	printf_array(a, N);
	printf_array(b, N);
	printf_array(c, N+1);
	
	return 0;
}

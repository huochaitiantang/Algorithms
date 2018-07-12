#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#define N 5
#define MAX 10

/* page 23: Honer method for
 *  	    f(x) = a0 + a1*x + a2*x^2 + ... + an*x^n
 *  	    	 = a0 + x*(a1 + x*(a2 + ... + x*(an-1 + x*an)...))
 * 	    O(n^2) down to O(n)
 */
int honer(int * a, int n, int x){
	int i,y = 0;
	for(i = n; i >= 0; i--){
		y = a[i] + x * y;
	}
	return y;
}

int main(){
	int * a;
	int i,j,x,y;
	srand((int)time(0));
	a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		a[i] = rand() % MAX;
	}
	x = rand() % MAX;
	printf("f(x) = ");
	for(i = N - 1; i > 0; i--){
		printf("%d*x^%d + ", a[i],i);
	}
	printf("%d \nf(%d) = ?\n", a[0],x);
	y = honer(a, N - 1, x);
	printf("Answer: f(%d) = %d\n", x, y);
	return 0;
}

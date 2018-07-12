#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5
#define MAX 10


/* page 24: thinking 2-4
 * 	calculate num of inversion pair:
 * 	modify the merge sort method,
 * 	O(n^2) down to O(nlgn)
 */
int inversion(int * a, int low, int high){
	int i,j,k,mid, n1, n2, n=0;
	int * tmp;
	if(high > low){
		tmp = (int *)malloc(sizeof(int) * (high - low + 1));
		mid = (low + high) / 2;
		n1 = inversion(a, 0, mid);
		n2 = inversion(a, mid+1, high);
		// sort the sub result, 
		// calculate the inversion by the way
		for(i = low, j = mid + 1, k = 0; i <= mid && j <= high; k++){
			if(a[i] <= a[j]){
				tmp[k] = a[i++];
			}
			else{
				// the inversion pair to add
				n = n + (mid - i + 1);
				tmp[k] = a[j++];
			}
		}
		while(i <= mid ) tmp[k++] = a[i++];
		while(j <= high) tmp[k++] = a[j++];
		for(i = low; i <= high; i++) a[i] = tmp[i - low];
		return (n1 + n2 + n);
	}
	else{
		return 0;
	}
}

int main(){
	int i,ans;
	int * a;

	srand((int)time(0));
	a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		a[i] = rand() % MAX;
		printf("%d ", a[i]);
	}
	ans = inversion(a, 0, N -1);
	printf("\nInversion pair: %d\n", ans);
	return 0;
}

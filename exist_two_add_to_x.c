#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100

// merge sort: nlgn
void merge_sort(int a[], int lenth, int low, int high){
	int i,j,k,mid;
	int * tmp;
	if(low < high){
		tmp = (int *)malloc(sizeof(int) * lenth);
		mid = (low + high) / 2;
		merge_sort(a, lenth, low, mid);
		merge_sort(a, lenth, mid + 1, high);
		// merge the sub sort result	
		for(i = low, j = mid + 1, k = 0; i <= mid & j <= high;){
			if(a[i] < a[j]){
				tmp[k++] = a[i++];
			}
			else{
				tmp[k++] = a[j++];
			}
		}
		while(i <= mid){
			tmp[k++] = a[i++];
		}
		while(j <= high){
			tmp[k++] = a[j++];
		}
		for(i = low; i <= high; i++){
			a[i] = tmp[i - low];
		}
	}
	return;
}

void printf_array(int a[], int lenth){
	int i;
	for(i = 0; i < lenth; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	return;
}


// scan from head and tail at the same time
int exist_two_add_to_x(int a[], int lenth, int x){
	int i,j,val;
	for(i = 0, j = lenth - 1; i < j;){
		val = a[i] + a[j];
		if(val == x){
			printf("a[%d]+a[%d]=%d(%d+%d=%d)\n",i,j,x,a[i],a[j],x);
			return 1;
		}
		if(val < x){
			i++;
		}
		else{
			j--;
		}
	}
	return 0;

}


// page22: practice 2.3-7
// Given x and if there exist m,n in array A that m + n = x
// Sort first, and scan from head and tail at the same time
// O(nlgn)
int main(){
	int i,x,exist;
	int * a;
	srand((int)time(0));
	a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		a[i] = rand() % 100;
	}
	x = rand() % 100;
	printf_array(a, N);
	merge_sort(a, N, 0, N-1);	
	printf_array(a, N);
	printf("x:%d\n", x);
	exist = exist_two_add_to_x(a, N, x);
	if(exist == 1) printf("Yes\n");
	else printf("No\n");

	return 0;
}

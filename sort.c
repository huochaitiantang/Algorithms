#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100

// page 10: INSERTION-SORT(A): O(n^2)
void insertion_sort(int a[], int lenth){
	int j,i,key;
	for(j = 1; j < lenth; j++){
		key = a[j];
		i = j - 1;
		while(i >= 0 && key < a[i]){
			a[i + 1] = a[i];
			i--;
		}
		a[i + 1] = key;
	}
	return;
}

// page 16: practice 2.2-2: O(n^2)
void selection_sort(int a[], int lenth){
	int i,j,key,ind;
	for(i = 0; i < lenth; i++){
		key = a[i];
		ind = i;
		for(j = i + 1; j < lenth; j++){
			if(a[j] < key){
				key = a[j];
				ind = j;
			}	
		}
		a[ind] = a[i];
		a[i] = key;
	}
	return;
}

// page 19: MERGE-SORY(A): O(nlgn)
void merge_sort(int a[], int lenth, int low, int high){
	int i,j,k,mid;
	int * tmp;
	tmp = (int *)malloc(sizeof(int)*lenth);
	if(low < high){
		mid = (low + high) / 2;
		merge_sort(a, lenth, low, mid);
		merge_sort(a, lenth, mid+1, high);
		// merge the sub sort result
		for(i = low, j = mid + 1, k = 0; i <= mid && j <= high; k++){
			if(a[i] < a[j]){
				tmp[k] = a[i];
				i ++;
			}
			else{
				tmp[k] = a[j];
				j ++;
			}
		}
		while(i <= mid){
			tmp[k++] = a[i];
			i ++;
		}
		while(j <= high){
			tmp[k++] = a[j];
			j ++;
		}
		for(i = low, k = 0; i <= high; i++, k++){
			a[i] = tmp[k];
		}
	}
	return;
}

// binary search max index where a[index] < x: O(lgn)
// index may = -1 for all a[i] >= x
int binary_search(int a[], int last, int x){
	int low,mid,high;
	low = 0;
	high = last;
	while(low <= high){
		mid = (low + high) / 2;
		if(a[mid] < x){
			low = mid + 1;
		}
		else{
			high = mid - 1;
		}
	}
	return high;
}

// page 22: paactice 2.3-6
// binary search for insertion sort: O(n^2)
void binary_search_insertion_sort(int a[], int lenth){
	int i,j,key,ind;
	for(i = 1; i < lenth; i++){
		key = a[i];
		ind = binary_search(a, i - 1, key);
		for(j = i - 1; j > ind; j --){
			a[j + 1] = a[j];
		}
		a[ind + 1] = key;
	}
	return;
}

// page 23: thinking 2-2
// bubble_sort: O(n^2)
void bubble_sort(int a[], int lenth){
	int i,j,tmp;
	for(i = 0; i < lenth; i++){
		for(j = lenth - 1; j > i; j--){
			if(a[j] < a[j - 1]){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}
	return;
}

// Max Heapify: make sure that A[i] satisfy heap feature
void max_heapify(int a[], int lenth, int top){
	int i, tmp;
	tmp = a[top];
	i = top * 2 + 1;
	while(i < lenth){
		if(i + 1 < lenth && a[i] < a[i + 1]) i++;
		if(tmp >= a[i]) break;
		a[(i - 1) / 2] = a[i];
		i = i * 2 + 1;
	}
	a[(i - 1) / 2] = tmp;
	return;
}


// page 87: heap sort
// O(nlgn)
void heap_sort(int a[], int lenth){
	int i,tmp;
	// build the heap
	for(i = lenth / 2; i >= 0; i--){
		max_heapify(a, lenth, i);
	}
	//
	for(i = lenth - 1; i >= 0; i--){
		tmp = a[i];
		a[i] = a[0];
		a[0] = tmp;
		max_heapify(a, i, 0);

	}
	return;
}


int  main(){
	int a[N];
	int i;
	srand((int)time(0));
	for(i = 0; i < N; i++){
		a[i] = rand() % 100;
		printf("%d ",a[i]);
	}
	printf("\n");
	//insertion_sort(a, N);
	//selection_sort(a, N);
	//merge_sort(a, N, 0, N-1);
	//binary_search_insertion_sort(a, N);
        //bubble_sort(a, N);
        heap_sort(a, N);
	for(i = 0; i < N; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

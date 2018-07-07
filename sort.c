#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100

// page 10: INSECTION-SORT(A)
void insection_sort(int a[], int lenth){
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

// page 16: practice 2.2-2
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

int  main(){
	int a[N];
	int i;
	srand((int)time(0));
	for(i = 0; i < N; i++){
		a[i] = rand() % 100;
		printf("%d ",a[i]);
	}
	printf("\n");
	//insection_sort(a, N);
	selection_sort(a, N);
	for(i = 0; i < N; i++){
		printf("%d ", a[i]);
	}
	printf("\n");

	return 0;
}

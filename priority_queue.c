#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define N 50
#define MAX 100

int maximum(int * a, int heap_size){
	return heap_size > 0 ? a[0] : 0;
}

void max_heapify(int * a, int heap_size, int top){
	int i,tmp;
	tmp = a[top];
	i = top * 2 + 1;
	while(i < heap_size){
		if(i + 1 < heap_size && a[i] < a[i + 1]) i++;
		if(tmp >= a[i]) break;
		a[(i - 1) / 2] = a[i];
		i = i * 2 + 1;
	}
	a[(i - 1) / 2] = tmp;
	return;
}

/* page 91: HEAP_EXTRACT_MAX
 * O(lgn)
 */ 
int heap_extract_max(int * a, int * heap_size){
	int tmp;
	tmp = a[0];
	a[0] = a[*heap_size - 1];
	*heap_size = *heap_size - 1;
	max_heapify(a, *heap_size, 0);
	return tmp;
}

/* page 91: HEAP_INCREASE_KEY
 * O(lgn)
 * increase a[i] to key
 */
void heap_increase_key(int * a, int heap_size, int i, int key){
	int parent, child;
	if(key <= a[i]){
		printf("Warning: key(%d) <= A[%d](%d)", key, i, a[i]);
		return;
	}
	child = i;
	parent = (child - 1) / 2;  // child = 0, parent = 0
	while(child > 0 && parent >= 0 && a[parent] < key){
		a[child] = a[parent];
		child = parent;
		parent = (child - 1) / 2;
	}
	a[child] = key;
	return;
}

/* page 92: MAX_HEAP_INSERT
 * O(lgn)
 */
void max_heap_insert(int * a, int * heap_size, int key){
	*heap_size = *heap_size + 1;
	a[*heap_size - 1] = key - 1;
	heap_increase_key(a, *heap_size, *heap_size - 1, key);
	return;
}

/* page 93: practice 6.5-8
 * DELETE_HEAP
 * O(lgn)
 */
void delete_heap(int * a, int * heap_size, int i){
	int j,k,tmp;
	if(i >= *heap_size) return;
	tmp = a[*heap_size - 1];
	*heap_size = *heap_size - 1;
	// from i to root
	if(a[i] <= tmp){
		j = (i - 1) / 2;
		while(i > 0 && tmp > a[j]){
			a[i] = a[j];
			i = j;
			j = (i - 1) / 2;
		}
		a[i] = tmp;
	}
	// from i to leaf
	else{
		j = i * 2 + 1;
		while(j < *heap_size){
			if(j + 1 < *heap_size && a[j + 1] > a[j]) j++;
			if(a[j] <= tmp) break;
			a[i] = a[j];
			i = j;
			j = i * 2 + 1;
		}
		a[i] = tmp;

	}
	return;
}


/* printf heap
 */
void print_heap(int * a, int heap_size){
	int i,j,k,h,w,x,base,num,space,first_space;
	h = (int)(log((float)heap_size + 0.5) / log(2.));
	//printf("heap_size:%d h:%d\n", heap_size, h);
	w = (int)pow(2, h);
	// level
	for(i = 0, base = 0; i <= h; i++){
		// num of level i
		num = (int)pow(2, i);

		// 2^h, 2^h-1, ... 2^0
		first_space = w / num;
		space = first_space * 2 -1;
		//space = w / (num + 1);
		if(i > 0){
			for(x = 0; x < first_space; x++) printf("  ");
			printf(" /");
			for(j = 1; j < num && j + base < heap_size; j++){
				for(x = 0; x < space; x++) printf("  ");
				if(j % 2 == 0) printf(" /");
				else printf(" \\");
			}
			printf("\n");

		}
		for(x = 0; x < first_space; x++) printf("  ");
		printf("%2d", a[base]);
		for(j = 1; j < num && j + base < heap_size; j++){
			for(x = 0; x < space; x++) printf("  ");
			printf("%2d", a[base + j]);
		}
		base += num;
		printf("\n");
	}
	return;
}

int main(){
	int * a;
	int * b;
	int tmp,i,heap_size=0;

	srand((int)time(0));
	a = (int *)malloc(sizeof(int) * N);
	b = (int *)malloc(sizeof(int) * N);
	
	for(i = 0; i < N; i++){
		tmp = rand() % MAX;
		b[i] = tmp;
		max_heap_insert(a, &heap_size, tmp);
	}
	for(i = 0; i < N; i++){
		printf("%d ", b[i]);
	}
	printf("\n");
	print_heap(a, heap_size);
	printf("Max: %d\n", maximum(a, heap_size));
	tmp = heap_extract_max(a, &heap_size);
	printf("Extract Max: %d\n", tmp); 
	print_heap(a, heap_size);
	tmp = 15;
	printf("Delete [%d]\n", tmp);
	delete_heap(a, &heap_size, tmp);
	print_heap(a, heap_size);

	return 0;
}

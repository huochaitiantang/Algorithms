#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100
#define MAX 100


/* page42: practice 4.1-2
 * find max subarray by violence
 * O(n^2) 
 */
void max_subarray_1(int * a, int lenth, int * left, int * right, int * sum){
	int i,j,l=-1,r,max_sum,cur_sum;
	int * b;
	b = (int *)malloc(sizeof(int) * lenth);
	// array b: b[i] is sum of a[0...i]
	for(i = 0; i < lenth; i++){
		b[i] = 0;
		for(j = 0; j <= i; j++){
			b[i] += a[j];
		}
		//printf("%d %d\n", i, b[i]);
	}
	// mas subarray of a
	for(i = 0; i < lenth; i++){
		for(j = i; j < lenth; j++){
			// cur_sum of a[i...j] 
			//  = b[j]           if i == 0
			//  = b[j] - a[i -1] if i > 0
			cur_sum = b[j];
			if(i > 0) cur_sum -= b[i - 1];
			//printf("cur sum: %d - %d: %d\n",i,j,cur_sum);
			if(l < 0 || cur_sum > max_sum){
				l = i;
				r = j;
				max_sum = cur_sum;
			}
		}
	}
	*left = l;
	*right = r;
	*sum = max_sum;
	return;
}

/* page41: algorithm FIND MAXIMUM SUBARRAY
 * O(nlgn)
 */
void max_subarray_2(int * a, int low, int high, int * left, int * right, int * sum){
	int i,mid, cur_sum, max_l_sum, max_r_sum, max_l, max_r;
	int l_left, l_right, l_sum;
	int r_left, r_right, r_sum;
	int c_left, c_right, c_sum;
	if(low == high){
		*left = low;
		*right = high;
		*sum = a[low];
		return;
	}
	else{
		mid = (low + high) / 2;
		// max subarray of a[low...mid]
		max_subarray_2(a, low, mid, &l_left, &l_right, &l_sum);
		// max subarray of a[mid+1...high]
		max_subarray_2(a, mid+1, high, &r_left, &r_right, &r_sum);
		// max subarray cross the a[mid]
		cur_sum = 0;
		max_l = -1;
		for(i = mid; i >= 0; i--){
			cur_sum += a[i];
			if(max_l < 0 || cur_sum > max_l_sum){
				max_l = i;
				max_l_sum = cur_sum;
			}
		}
		cur_sum = 0;
		max_r = -1;
		for(i = mid + 1; i <= high; i++){
			cur_sum += a[i];
			if(max_r < 0 || cur_sum > max_r_sum){
				max_r = i;
				max_r_sum = cur_sum;
			}
		}
		c_left = max_l;
		c_right = max_r;
		c_sum = max_l_sum + max_r_sum;
		// get the max sub array among three conditions
		if(l_sum >= r_sum && l_sum >= c_sum){
			*left = l_left;
			*right = l_right;
			*sum = l_sum;
		}
		else if(c_sum >= l_sum && c_sum >= r_sum){
			*left = c_left;
			*right = c_right;
			*sum = c_sum;
		}
		else{
			*left = r_left;
			*right = r_right;
			*sum = r_sum;
		}
		return;
	}
}


int main(){

	int i;
	int v_left,v_right,v_sum;
	int m_left,m_right,m_sum;
	int * a;

	srand((int)time(0));
	a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		a[i] = rand() % MAX - MAX / 2;
		printf("%d ", a[i]);
	}
	printf("\n");
	max_subarray_1(a, N, &v_left, &v_right, &v_sum);
	printf("(Violence) Max SubArray: %d - %d (sum = %d)\n", v_left, v_right, v_sum);
	max_subarray_2(a, 0, N-1, &m_left, &m_right, &m_sum);
	printf("(  Merge ) Max SubArray: %d - %d (sum = %d)\n", m_left, m_right, m_sum);
	return 0;

}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10000
#define MAX 1000


/* page 42: practice 4.1-2
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
	// max subarray of a
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

/* page 41: algorithm FIND MAXIMUM SUBARRAY
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


/* page 42: practice 4.1-5
 * find max subarray by violence
 * O(n)
 * max subarray of a[0...i-1] is a[l...r],
 * get the max subarray of a[0...i]:
 * a[l...r] or a[l...i] or a[new_l...i](new_l > r)
 * record r2i_sum: a[r+1...i]
 * record k2i_sum: max of a[k...i] (r+1 <= k <= i)
 * compare a[l...r], a[l...r]+a[r+1...i], a[k...i]
 */
void max_subarray_3(int * a, int lenth, int * left, int * right, int * sum){
	int i,l,r,s;
	int r2i_sum, k2i_sum, k; 
	s = a[0];
	l = r = 0;
	r2i_sum = 0;
	k2i_sum = 0;
	k = 1;

	for(i = 1; i < lenth; i++){
		//sum of a[r+1...i]
		r2i_sum += a[i];
		//max sum of a[k...i] (r+1 <= k <= i)
		k2i_sum += a[i];
		if(k2i_sum < a[i]){
			k = i;
			k2i_sum = a[i];
		}
		//compare s, r2i_sum+s, k2i_sum
		if(r2i_sum > 0){
			s = r2i_sum + s;
			r = i;
			r2i_sum = 0;
		}
		if(k2i_sum > s){
			s = k2i_sum;
			l = k;
			r = i;
			r2i_sum = 0;
			k2i_sum = 0;
			k = i + 1;
		}
	}
	*left = l;
	*right = r;
	*sum = s;
	return;
}


/* find max subarray by greed: O(n)
 */ 
void max_subarray_4(int * a, int lenth, int * left, int * right, int * sum){
	int i, cur_sum=0, pre_l=0, cur_l=0, cur_r=-1, max_sum;
	for(i = 0; i < lenth; i++){
		cur_sum += a[i];
		if(cur_r < 0 || cur_sum > max_sum){
			cur_l = pre_l;
			cur_r = i;
			max_sum = cur_sum;
		}
		// if cur_sum <= 0, the max sub array should begin at i+1
		if(cur_sum <= 0){
			pre_l = i + 1;
			cur_sum = 0;
		}
	}
	*left = cur_l;
	*right = cur_r;
	*sum = max_sum;
	return;
}

int main(){

	int i;
	int v_left,v_right,v_sum;
	int m_left,m_right,m_sum;
	int l_left,l_right,l_sum;
	int g_left,g_right,g_sum;
	int * a;
	clock_t t0, t1;

	srand((int)time(0));
	a = (int *)malloc(sizeof(int) * N);
	for(i = 0; i < N; i++){
		a[i] = rand() % MAX - MAX / 2;
		printf("%d ", a[i]);
	}
	printf("\n");
	t0 = clock();
	max_subarray_1(a, N, &v_left, &v_right, &v_sum);
	t1 = clock();
	printf("(Violence) Max SubArray: %d - %d (sum = %d) cost: %f ms\n", v_left, v_right, v_sum, (float)(t1-t0)/CLOCKS_PER_SEC*1000);
	
	t0 = clock();
	max_subarray_2(a, 0, N-1, &m_left, &m_right, &m_sum);
	t1 = clock();
	printf("(Merge   ) Max SubArray: %d - %d (sum = %d) cost: %f ms\n", m_left, m_right, m_sum, (float)(t1-t0)/CLOCKS_PER_SEC*1000);
	
	t0 = clock();
	max_subarray_3(a, N, &l_left, &l_right, &l_sum);
	t1 = clock();
	printf("(Linear  ) Max SubArray: %d - %d (sum = %d) cost: %f ms\n", l_left, l_right, l_sum, (float)(t1-t0)/CLOCKS_PER_SEC*1000);
	
	t0 = clock();
	max_subarray_4(a, N, &g_left, &g_right, &g_sum);
	t1 = clock();
	printf("(Greed   ) Max SubArray: %d - %d (sum = %d) cost: %f ms\n", g_left, g_right, g_sum, (float)(t1-t0)/CLOCKS_PER_SEC*1000);
	return 0;

}

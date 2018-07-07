#include<stdio.h>
#include<math.h>

/* page 8: practice 1-1
 * Given solving  time f(n) ms, 
 * calculate the biggest n for 
 * a second, a minute, an hour, a day, 
 * a month, a year and a century.
 */

#define N 7

// f(n) = log(n)
double * log_n(double upper[]){
	double  *ans;
	int i;
	ans = (double *)malloc(sizeof(double)*N);
	for(i = 0; i < N; i++){
		ans[i] = pow(2, upper[i]);
	}
	return ans;
}

// f(n) = sqrt(n)
double * sqrt_n(double upper[]){
	double  *ans;
	int i;
	ans = (double *)malloc(sizeof(double)*N);
	for(i = 0; i < N; i++){
		ans[i] = pow(upper[i],2);
	}
	return ans;
}

// f(n) = n
double * n(double upper[]){
	double  *ans;
	int i;
	ans = (double *)malloc(sizeof(double)*N);
	for(i = 0; i < N; i++){
		ans[i] = upper[i];
	}
	return ans;
}

// get x for xlogx = y with binary search
double binary_getx(double y, double delta){
	double low = 1.;
	double hig = 3e12;
	while(hig - low > delta){
		double mid = (low + hig) / 2.;
		double midvalue = mid * log(mid) / log(2.);
		if(midvalue == y){
			hig = low = mid;
		}
		else if(midvalue < y){
			low = mid;
		}
		else if(midvalue > y){
			hig = mid;
		}
	}
	return low;
}

// f(n) = nlog(n)
double * nlog_n(double upper[]){
	double  *ans;
	int i;
	ans = (double *)malloc(sizeof(double)*N);
	for(i = 0; i < N; i++){
		ans[i] = binary_getx(upper[i], 0.001);
	}
	return ans;
}

// f(n) = n^2
double * n_n(double upper[]){
	double  *ans;
	int i;
	ans = (double *)malloc(sizeof(double)*N);
	for(i = 0; i < N; i++){
		ans[i] = sqrt(upper[i]);
	}
	return ans;
}

// f(n) = n^3
double * n_n_n(double upper[]){
	double  *ans;
	int i;
	ans = (double *)malloc(sizeof(double)*N);
	for(i = 0; i < N; i++){
		ans[i] = pow(upper[i], 1./3);
	}
	return ans;
}

// f(n) = 2^n
double * f_2_n(double upper[]){
	double  *ans;
	int i;
	ans = (double *)malloc(sizeof(double)*N);
	for(i = 0; i < N; i++){
		ans[i] = log(upper[i]) / log(2.);
	}
	return ans;
}

// f(n) = n!
double * fac_n(double upper[]){
	double  *ans;
	int i,k=0;
	double cur=1.0;
	ans = (double *)malloc(sizeof(double)*N);
	for(i = 1; ; i++){
		cur *= i;
		printf("%lf\n",cur);
		if(cur > upper[k]){
			ans[k] = i - 1;
			k ++;
			if(k >= 7) break;
		}
	}
	return ans;
}

int main(){
	// second,minute,hour,day,month,year,century
	double upper[N] = {1000};
	double * ans;
	int times[N] = {1, 60, 60, 24, 30, 12, 100};
	int i;
	
	for(i = 1; i < N; i++){
		upper[i] = upper[i-1] * times[i];
	}

	//ans = log_n(upper);
	//ans = sqrt_n(upper);
	//ans = n(upper);
	//ans = nlog_n(upper);
	//ans = n_n(upper);
	//ans = n_n_n(upper);
	//ans = f_2_n(upper);
	ans = fac_n(upper);
	for(i = 0; i < N; i++){
		printf("%d : %e ms %e\n",i,upper[i],ans[i]);
	}

	return 0;


}


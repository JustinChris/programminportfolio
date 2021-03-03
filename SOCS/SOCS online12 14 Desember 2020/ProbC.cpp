#include <stdio.h>
#include <math.h>

int main() {
	int t,n;
	scanf("%d",&t);
	for(int i = 0; i < t; i++) {
		double mean = 0;
		double median;
		int temp;
		scanf("%d",&n);
		int A[n];
		for (int j = 0; j < n;j++) {
			scanf("%d",&A[j]);
			mean += A[j];
		}
		for (int j = 0; j < n;j++) {
			for(int k = 0; k < n;k++) {
				if (A[j] < A[k]) {
					temp = A[k];
					A[k] = A[j];
					A[j] = temp;
				}
			}
		}
		if (n % 2 != 0) {
			median = A[n/2];
		}else if (n%2 == 0) {
			median = (A[n/2] + A[n/2-1])/2.0;
		}
		mean = mean/n;
		printf("Case #%d:\n",i+1);
		printf("Mean : %.2lf\n",mean);
		printf("Median : %.2lf\n",median);
	}
	return 0;
}

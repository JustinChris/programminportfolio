#include <stdio.h>

int main() {
	long long int n,m;
	scanf("%lld",&n);
	long long int arr[n][n];
	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n;j++) {
			scanf("%lld",&arr[i][j]);
		}
	}
	scanf("%lld",&m);
	long long int total;
	long long int total2 = 0;
	for (int i = 0; i < n-m+1;i++) {
		for (int j = 0; j < n-m+1;j++) {
			total = 0;
			for (int k = i;k < m+i;k++) {
				for (int l = j; l < m+j;l++) {
					total += arr[k][l];
				}
			}
			if (total2 < total) {
				total2 = total;
			}
		}
	}
	printf("%lld\n",total2);
	return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
	int t;
	scanf("%d",&t);
	for (int i = 0; i < t;i++) {
		long long int answer;
		long long int r = 10000000000000000, l = 1,j;
		scanf("%lld",&j);
		while(l <= r) {
			long long int n = (l+r)/2;
			if (0.166666666666666666666 * n * (n+1) * (2*n+1) >= j) {
				answer = n;
				r = n-1;
			}
			else {
				l = n+1;
			}
		}
	
		printf("Case #%d: %lld\n",i+1,answer); answer = 0;
	}
	
	
	
	return 0;
}

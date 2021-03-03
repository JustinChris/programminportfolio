#include <stdio.h>

int main() {
	long long int T,N,x1 = 0,x = 0;
	long long int A[5000];
	
	scanf("%lld",&T);
	for (int i = 0; i < T; i++){
		scanf("%lld",&N);
		for(int j = 0; j < N;j++){
			scanf("%lld",&A[j]);
			x += A[j];
			if (x < x1) {
				x1 = x;
			}
		}
			printf("Case #%lld: %lld\n",i+1,1-x1);
			x1 = 0;
			x = 0;
	}
	return 0;
}

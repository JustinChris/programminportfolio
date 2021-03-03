#include <stdio.h>

int main() {
	long long int N,M,L,R,total = 0;
	long long int A[200];
	scanf("%lld %lld",&N,&M);
	for (int i = 0; i < N; i++){
		scanf("%lld",&A[i]);
		}
	for (int j = 0; j < M; j++){
		scanf("%lld %lld",&L,&R);
		for (int k = L; k <= R; k++){
			if (k % 2 == 0){
				total += A[k-1];
			}
		}
		printf("%lld\n",total);total = 0;
	}
	return 0;
}

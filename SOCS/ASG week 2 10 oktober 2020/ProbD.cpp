#include <stdio.h>

int main() {
	long long int N,K;
	long long int result;
	long long int y;
	scanf("%lld %lld",&N,&K);
	
	if (N > K){
		result = N - K;
	}else if (N < K){
		y = K % N;
		result = N - y;
	}
	
	printf("%lld\n",result);
	return 0;
}

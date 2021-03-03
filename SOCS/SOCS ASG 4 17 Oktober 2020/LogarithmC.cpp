#include <stdio.h>

int main() {
	
	int T, K, N, D = 0;
	scanf("%d", &T);
	for(int i=0;i<T;i++){
		scanf("%d %d", &N, &K);
		
		for(int j=K;j<=N;j*=K){
			D++;
		}
		printf("Case #%d: %d\n", i+1, D);
		D=0;
	}
	return 0;
}

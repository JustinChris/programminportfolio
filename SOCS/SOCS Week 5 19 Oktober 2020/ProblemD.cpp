#include <stdio.h>

int main() {
	long long int T,N,ang[1001],tam[1001],s = 0,count = 1;
	
	scanf("%lld",&T);
	for (int i = 0; i < T; i++){
		scanf("%lld", &N);
		
		for (int j = 0; j < N; j++){
			scanf("%lld",&ang[j]);
		}
			printf("Case #%lld:",count);
			for (int k = N; k > 0; k-=2){
				tam[s] = ang[k-2];
				tam[s+1] = ang[k-1];
				printf(" %lld",tam[s]);
				printf(" %lld",tam[s+1]);
				s+=2;
		}
		count++;
		printf("\n"); s = 0;
	}
	
	return 0;
}

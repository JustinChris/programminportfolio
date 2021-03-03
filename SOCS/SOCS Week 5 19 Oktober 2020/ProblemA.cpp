#include <stdio.h>

int main() {
	long long int T,N, max1 = -1000001, max2 = -1000001,total;
	scanf("%lld",&T);
	for (int i = 0; i < T; i++){
		scanf("%lld",&N);
		long long int x[N];
		for (int j = 0; j < N; j++){
			scanf("%lld",&x[j]);
		}
		for (int j = 0; j < N; j++){
			
			if(x[j] > max1) {
				max2 = max1;
				max1 = x[j];
			}else if (x[j] > max2 && x[j] < max1){
				max2 = x[j];
			}else if (x[j] == max1){
				max2 = max1;
				max1 = x[j];
			}
		}
		total = max1 + max2;
		printf("Case #%d: %lld\n",i+1,total); max1 = 0; max2 = 0;
	}
	
	
	return 0;
}

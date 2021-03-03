#include <stdio.h>

int main() {
	long long int T, x, N, count = 0,Penj = 0,flag = 0;;
	int Arr[300000] = {0};
	
	scanf("%lld",&T);
	
	for(int i = 0; i < T; i++){
		scanf("%lld",&N);
		for (int j = 0; j < N; j++){
			scanf("%lld",&x);
			Arr[x]++;
			if(Arr[x] > flag){
				flag = Arr[x];
			}
		}
		
		for (int k = 1; k <= 100001; k++){
			if (Arr[k] == flag) {
				count += k;
			}
			Arr[k] = 0;
		}
		flag = 0;
		printf("Case #%d: %lld\n",i+1,count); count = 0;
	}
	
	return 0;
}

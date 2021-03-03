#include <stdio.h>

int main() {
	long long int T,N,M;
	scanf("%lld",&T);
	for (int i = 0; i < T;i++){
		long long int hasil = 1, d = 0, total = 0;
		scanf("%lld %lld",&N,&M);
		total = N * M;
		while (d < total){
			hasil *= 2;
			d++;
		}
		printf("Case #%d: %lld\n",i+1,hasil);
	}
	return 0;
}

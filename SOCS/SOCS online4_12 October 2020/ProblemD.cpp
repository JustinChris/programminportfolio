#include <stdio.h>

int main() {
	long long int N,X,Y;
	long long int as;
	long long int resGen = 0,resGan = 0;
	long long int final;
	
	scanf("%lld %lld %lld",&N,&X,&Y);
	
	for(int i = 0; i < N; i++){
		scanf("%lld",&as);
		if (as % 2 == 0){
			resGen = resGen + (as * Y);

		}else {
			resGan = resGan + (as * X);

		}
		final = resGan + resGen;
	}
	
	
	
	printf("%lld\n",final);
	
	
	
	return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
	long long int T,N,pangkat = 0, y = 2, z = 0, x = 1;;
	
	
	scanf("%lld",&T);
	for (int i = 0; i < T;i++) {
		scanf("%d", &N);
		printf("Case #%d: ",i+1);
		
		while (N%2 == 0) {
			N = N/2;
			pangkat++;
		}
			if(pangkat != 0 && N != 1){   // buat ngeprint pangkat skrng
				printf("%d ^ %d ", y, pangkat); 
				pangkat = 0;
				printf("* ");
			}else if (pangkat != 0 && N == 1){
				printf("%d ^ %d", y, pangkat);
				pangkat = 0;
			}
		
		for (int j = 3; j <= sqrt(N);j += 2){
			while (N%j == 0) {
				N = N / j;
				pangkat++;
			}
			if(pangkat != 0 && N != 1){   // buat ngeprint pangkat skrng
				printf("%d ^ %d ", j, pangkat); 
				pangkat = 0;
				printf("* ");
			}else if (pangkat != 0 && N == 1){
				printf("%d ^ %d", j, pangkat);
				pangkat = 0;
			}
		}
		if (N > 2){
			printf("%d ^ %d", N, 1);
		}
		printf("\n");
	}
	
	return 0;
}



#include <stdio.h>

int main() {
	int A,B,C = 0,D,E,hasil;
	int T;
	scanf("%d",&T);
	
	for (int i = 0; i < T;i++){
		scanf("%d %d",&A, &B);
		hasil = A;
		
		while (C>=B){
			
		C = A/B;
		hasil += C;
		D = A%B;
		if (D != 0) {
			E = (D+C)/B;
		}
		hasil += E;
		}
		
		
		printf("%d\n",hasil); C = 0; D = 0; E = 0; hasil = 0;
		
	}
	
	return 0;
}

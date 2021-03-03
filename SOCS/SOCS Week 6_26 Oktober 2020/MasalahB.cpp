#include <stdio.h>


int main() {
	int N;
	scanf("%d",&N);
	long long int hasil = 1;
	while (N > 0){
		hasil *= 2;
		N--;
	}
	hasil = hasil - 1;
	printf("%lld\n",hasil); hasil = 1;
	
	
	return 0;
}

#include <stdio.h>

int main() {
	long long int a,b,c,d;
	long long int lr,rr;

	
	scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
	
	lr = a * b;
	rr = c + d;
	
	if (lr > rr) {
		printf("True\n");
	}else if (lr < rr){
		printf("False\n");
	}

	
	return 0;
}

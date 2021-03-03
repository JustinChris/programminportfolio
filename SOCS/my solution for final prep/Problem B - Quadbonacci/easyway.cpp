#include <stdio.h>

int rec (int n) {
	if (n == 1 || n == 2)
		return 0;
	if (n == 3 || n == 4)
		return 1;
	else {
		return rec(n-1) + rec(n-2) + rec(n-3) + rec(n-4);
	}
}


int main() {
	long long int n;
	scanf("%lld",&n);
	printf("%lld",rec(n));
	
	return 0;
}

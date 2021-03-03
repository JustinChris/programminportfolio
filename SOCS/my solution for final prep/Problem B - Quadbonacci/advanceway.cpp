#include <stdio.h>

long long int memo[10000] = {0};

int rec(int n) {
	if (n == 1 || n == 2) return 0;
	if (n == 3 || n == 4) return 1;
	else if (memo[n] != 0){
		return memo[n];
	}
	return memo[n] = rec(n-1) + rec(n-2) + rec(n-3) + rec(n-4);
}


int main() {
	long long int n;
	puts("Masukan angka untuk di rekursi");
	scanf("%d",&n);
	printf("%d",rec(n));
	return 0;
}

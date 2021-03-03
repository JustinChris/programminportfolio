#include <stdio.h>

int a[100000];
int fibo(int n){
	if (n == 1)
		return 1;
	if (n == 0)
		return 0;
	if (a[n] != 0)
		return a[n];
	return a[n] = fibo(n-1) + fibo(n-2);
	
		
	}

int main() {
	int x;
	scanf("%d",&x);
	printf("%d",fibo(x));
	
	return 0;
}

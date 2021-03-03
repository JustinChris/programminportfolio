#include <stdio.h>



int fibo (int n) {
	int memo[10000];
	if (n == 0) 
		return 0;
	if (n == 1) 
		return 1;
	if (memo[n] != 0)
		return memo[n];
	return memo[n] = fibo(n-1) + fibo(n-2);
	
}

int main() {
//	int n = 3;
	//supposed to be like this
	// abc
	// def
	// ghi
//	char arr[5][5];
	
//	for (int i =0; i < n; i++) {
//		for (int j = 0; j < n;j++){
//			scanf("%c",&arr[i][j]);
//		}
//	}
//	
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("%c",arr[i][j]);
//		}
//	}
	
//	for (int i = 0; i < n; i++) {
//		scanf("%s",arr[i]);
//	}
//	
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			printf("%c",arr[i][j]);
//		}
//		printf("\n");
//	}
	
	int n;
	
	printf("Masukan Angka yang ingin di cari Fibonaccinya\n");
	scanf("%d",&n);
	printf("%d",fibo(n-1));
	
	
	
}

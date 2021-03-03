#include <stdio.h>

void sort (long long int arr[],long long int r) {
	for (int i = 0; i < r;i++) {
		for (int j = 0; j < r;j++) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void sort2 (long long int arr[],long long int r) {
	for (int i = 0; i < r;i++) {
		for (int j = 0; j < r;j++) {
			if (arr[i] > arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main() {
	int t,n;
	scanf("%d",&t);
	for (int i = 0; i < t;i++) {
		long long int sum = 0;
		
		scanf("%d",&n);
		
		long long int A[n+10];
		long long int B[n+10];
		
		for (int j = 0; j < n;j++) {
			scanf("%lld",&A[j]);
		}
		sort(A,n);
		for (int j = 0; j < n;j++) {
			scanf("%lld",&B[j]);
		}
		sort2(B,n);
		for (int j = 0; j < n;j++) {
			sum = sum + (A[j] * B[j]);
		}
		printf("Case #%d: %lld\n",i+1,sum); 
		sum = 0;
	}
	return 0;
}

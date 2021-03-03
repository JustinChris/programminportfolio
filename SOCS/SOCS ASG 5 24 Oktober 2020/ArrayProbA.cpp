#include <stdio.h>

int main() {
	int n,x;
	scanf("%d",&n);
	int A[n],B[n],tamp[n];
	for (int i = 0; i < n; i++){
		scanf("%d",&A[i]);
	}
	for (int j = 0; j < n; j++){
		scanf("%d",&B[A[j]]);
	}
	for (int k = 0; k < n; k++){
		printf("%-d",B[k]);
		if (k < n-1){
			printf(" ");
		}
	}
	printf("\n");
	return 0;
}

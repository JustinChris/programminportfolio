#include <stdio.h>

int main() {
	int N;
	int A[10000];
	scanf("%d",&N);
	for(int i = 0; i < N;i++){
		scanf("%d",&A[i]);
	}
	for(int j = 0; j < N;j++){
		for(int d = A[j]; d > 0;d--){
			printf("#");
		}
		for(int s = 9 - A[j];s > 0;s--){
			printf(".");
		}
		printf("\n");
	}
	
	return 0;
}

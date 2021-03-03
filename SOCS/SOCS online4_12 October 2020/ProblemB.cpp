#include <stdio.h>

int main() {
	int N,K;
	
	scanf("%d %d",&N,&K);
	//kotak 1
	for(int i = 0; i < N;i++){
		for(int j = 0; j < N;j++){
			printf("#");
		}
		printf("\n");
	}
	printf("\n");
	//kotak 2
	for (int x = 1; x <= N;x++) {
		for(int y = 0; y < N; y++){
			if(x % K == 0){
				printf("#");
			}else {
				printf(".");
			}
		}
		printf("\n");
	}
	printf("\n");
	
	//kotak 3
	for(int a = 0; a < N;a++){
		for(int b = 1; b <= N;b++){
			if(b % K == 0){
				printf("#");
			}else {
				printf(".");
			}
		}
		printf("\n");
	}
	
	return 0;
}

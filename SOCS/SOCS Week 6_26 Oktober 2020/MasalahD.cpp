#include <stdio.h>

int main() {
	int T, N;
	scanf("%d",&T);
	for (int i = 0; i < T; i++){
		scanf("%d", &N);
			printf("Case #%d:\n",i+1);
		for(int j = 1; j <= N;j++){
			for (int k = j; k < N;k++){
				printf(" ");
			}
			for (int d = 1; d <= j; d++){
				if((d+N)%2 == 0){
					printf("*");
					
				}else{
					printf("#");
				}
			}
			printf("\n");
		}

	}
	return 0;
}

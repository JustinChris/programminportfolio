#include <stdio.h>

int main() {
	int T, N,x;
	long long int isi[1000];
	scanf("%d", &T);
	
	for (int i = 0; i < T;i++){
		scanf("%d",&N);
		for (int j = 0; j < N;j++){
			scanf("%d",&isi[j]);
		}
		printf("Case #%d:",i+1);
		for(int k = N-1; k >= 0;k--){
			printf(" %d",isi[k]);
		}
		printf("\n");
	}
	
	return 0;
}

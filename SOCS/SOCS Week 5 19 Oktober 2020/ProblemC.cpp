#include <stdio.h>

int main() {
	long long int T,x,a,b;
	long long int sum[101];	
	scanf("%lld",&T);
	
	for (int i = 0; i < T; i++){
		scanf("%lld",&x);
		long long int mat[x][x];
		for (int j = 0; j < x; j++){
			for (int k = 0; k < x; k++){
				scanf("%lld", &mat[j][k]);
			}
		}
		printf("Case #%d:",i+1);
		for (int a = 0; a < x; a++){
			sum[a] = 0;
			for(int b = 0; b < x; b++){
				sum[a] += mat[b][a];
			}
			printf(" %lld",sum[a]);
		}
		printf("\n");
	}
	
	
	return 0;
}

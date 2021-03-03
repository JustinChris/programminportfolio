#include <stdio.h>

int main () {
	int t,n,max,count,din;
	scanf("%d",&t);
	for(int i = 1; i <= t; i++){
		scanf("%d",&n);
		long int A[2][n];
		for(int j = 0;j < 2;j++){
			for(int k = 0; k < n; k++){
				scanf("%ld",&A[j][k]);
			}
		}
		max = 0;
		for(int i = 0; i < n;i++){
			count = 0;
			for(int j = 0; j < n;j++){
				din = (i + j) % n;
				if(A[1][j] > A[0][din]) {
					count++;
				}
			}
				if(max < count) {
					max = count;
				}
			}
		printf("Case #%d: %d\n",i, n+max);
	}
return 0;
}

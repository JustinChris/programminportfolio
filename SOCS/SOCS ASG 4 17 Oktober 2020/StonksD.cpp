#include <stdio.h>

int main() {
	int X,Y,N,T;
	int A;
	long long int B;
	
	scanf("%d",&T);
	
	for (int i = 0; i < T; i++) {
		scanf("%d",&N);
		for (int j = 0; j < N; j++){
			scanf("%d %lld", &A,&B);
			if (A == 0) {
				X += B;
				//buying
			}else if (A == 1){
				//selling
				X -= B;
			}
		}
			printf("Case #%d: %d\n",i+1,X);
			X = 0;
	}
	
	return 0;
}

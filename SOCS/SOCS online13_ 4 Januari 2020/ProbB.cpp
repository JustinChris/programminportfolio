#include <stdio.h>
// N banyak angka yang masuk ke bag
// M banyak angka yang diambil dari bag
int main() {
	int N,M,total = 0;
	int all = 0;
	int ArrN[105];
	int ArrM[105];
	scanf("%d %d",&N,&M);
	for (int i = 0; i < N;i++) {
		scanf("%d",&ArrN[i]);
	}
	for (int i = 0; i < M;i++) {
		scanf("%d",&ArrM[i]);
		for (int j = 0; j < N;j++) {
			if (ArrM[i] == ArrN[j]){
				ArrN[j] = 0;
			}
		}
	}
	for (int i= 0; i < N;i++) {
		if (total < ArrN[i]) {
			total = ArrN[i];
		}
		if (ArrN[i] == 0) {
			all++;
			
		}
	}
	if (all == N) {
		printf("Maximum number is -1\n");
	}else {
		printf("Maximum number is %d\n",total);
	}
	
	return 0;
}

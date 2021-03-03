#include <stdio.h>

int main() {
	int N;
	scanf("%d",&N);
	int a[N+1];
	int result[100];
	int step = 0;
	
	
	for (int i = 0; i < N; i++){
		scanf("%d",&a[i]);
		if (a[i] == 1){
			step++;
			result[step] = 1;
		}else {
			result[step] = a[i];
		}
	}
	for (int j = 1; j <= step; j++){
		if(j != step) {
			printf("%d ",result[j]);
		}else {
			printf("%d\n",result[j]);
		}
	}
	return 0;
}

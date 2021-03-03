#include <stdio.h>

int main() {
	int N,Q,x,p1,p2,jumlah;
	int view[101];
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d",&view[i]);
	}
	scanf("%d",&x);
	for (int j = 0; j < x; j++){
		scanf("%d %d",&p1,&p2);
		jumlah = view[p1-1];
		for (int k = p1 - 1; k < p2-1; k++){
			jumlah += view[k+1];
		}
		printf("Case #%d: %d\n",j+1,jumlah);
	}
	return 0;
}

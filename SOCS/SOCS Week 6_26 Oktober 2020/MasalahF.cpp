#include <stdio.h>

int main() {
	int n,m;
	long long A[102] = {0},x;
	unsigned long long total;
	scanf("%d %d",&n,&m);
	total = 1;
	for(int i = 0; i < n;i++){
		for (int j = 0;j < m;j++){
			scanf("%d",&x);
			A[j] += x;
			A[j] %= 1000000007;
		}
	}
	for(int i = 0; i < m;i++){
		total*=A[i];
		total %= 1000000007;
	}
	printf("%lld\n", total);
	return 0;
}

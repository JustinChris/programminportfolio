#include <stdio.h>

int main() {
	int t,n;
	unsigned long long int d;
	unsigned long long int s = 0;
	scanf("%d",&t);
	for (int i = 0; i < t;i++){
		scanf("%d",&n);
		for(int j = 1; j <= n;j++){
			scanf("%llu",&d);
			if (j % 2 == 0){
				s += d;
			}
		}
		printf("Case #%d: %llu\n",i+1,s); s = 0; d = 0;
	}
	return 0;
}

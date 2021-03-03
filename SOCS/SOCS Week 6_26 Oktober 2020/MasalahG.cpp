#include <stdio.h>

int main() {
	int T,N;
	scanf("%d",&T);
	for (int i = 0;i<T;i++){
		scanf("%d",&N);
		int s[100000] = {0};
		int langkahmaks = 0;
		int langkah = 0;
		int d = 0;
		for (int j = 1; j <= N;j++){
			scanf("%d",&s[j]);
			if (j == 1){
				d = s[j];
			}
		}
		for (int j = 1; j <= N;j++){
			if (s[j+1] - s[j] > langkahmaks){
				langkahmaks = s[j+1] - s[j];
			}
		}
		for (int j = 1; j <= N; j++){
			d += langkahmaks;
			while (d > s[j]){
				j++;
			}
			if(d < s[j]){
				while(d!=s[j-1]){
					d--;
				}
				j--;
			}
			langkah++;
		}
		printf("Case #%d: %d %d\n", i+1,langkahmaks,langkah);
	}
	return 0;
}

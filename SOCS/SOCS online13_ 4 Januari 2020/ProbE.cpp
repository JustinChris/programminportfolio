#include <stdio.h>

int main() {
	int t,a,b,c,max;
	int total = 0;
	scanf("%d",&t);
	for (int i = 0; i < t; i++) {
		scanf("%d",&a);
		int ArrA[a];
		for (int j = 0; j < a;j++) {
			scanf("%d",&ArrA[j]);
		}
		scanf("%d",&b);
		int ArrB[b];
		for (int j = 0; j < b;j++) {
			scanf("%d",&ArrB[j]);
		}
		scanf("%d",&c);
		int ArrC[c];
		for (int j = 0; j < c;j++) {
			scanf("%d",&ArrC[j]);
		}
		scanf("%d",&max);
		// looping
		for (int j = 0; j < a;j++) {
			for (int s = 0; s < b;s++){
				for (int k = 0; k < c;k++) {
					if ((ArrA[j] + ArrB[s] + ArrC[k]) == max) {
						total++;
					}
				}
			}
		}
		printf("Case #%d: %d\n",i+1,total);total = 0;
	}
	return 0;
}

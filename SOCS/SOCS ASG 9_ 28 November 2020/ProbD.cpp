#include <stdio.h>

int main() {
	int t,n,sc = 0;
	scanf("%d",&t);
	for (int i = 0; i < t;i++){
		scanf("%d",&n);
		while (n > 0){
			if (n >= 50) {
				sc++;
				n -= 50;
			}else if (n >= 10 && n < 50){
				sc++;
				n -= 10;
			}else if (n >= 5 && n < 10) {
				sc++;
				n -= 5;
			}else if (n >= 2 && n < 5){
				sc++;
				n -= 2;
			}else {
				sc++;
				n -= 1;
			}
		}
		printf("Case #%d: %d\n",i+1,sc); sc = 0;
		
	}
	return 0;
}

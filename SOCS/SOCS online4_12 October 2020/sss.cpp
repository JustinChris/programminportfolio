#include <stdio.h>

int main() {
	int n,T;
	scanf("%d",&T);
	for (int i = 0; i < T;i++){
	
	scanf("%d", &n);
	int cur_factor = 2;
	while( cur_factor < n) {
		if (n % cur_factor == 0) {
			int expo = 0;
			while(n % cur_factor == 0) {
				n = n/cur_factor;
				expo++;
				//print pangkatnya
			}
			if(expo != 0) {
				printf("Case #%d: %d ^ %d",i+1,cur_factor,expo);
			}
			else {
				printf("%d\n", cur_factor);
			}
			if (n != 1) {
				printf(" * ");
			}
		}
		cur_factor++;
	}
	if( n != 1){
		printf("%d ^ 1",cur_factor);
	}}
	printf("\n");
	return 0;
}

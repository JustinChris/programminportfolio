#include <stdio.h>
#include <math.h>

int main() {
	int t;
	int ds;
	int arr_memo[1000] = {0};
	unsigned long long int m,b = 0,c= 0;
	scanf("%d",&t);
	for (int i = 0; i < t;i++) {
		scanf("%llu",&m);
		for (int j = 1; b < m;j++) {
//			if (arr_memo[j] == 0) {
//				arr_memo[j] = 1/6 * j*(j+1) * (2*j+1);
//				
//			}
//			if (arr_memo[j] != 0){
//				b = arr_memo[j];
//				printf("%d",b);
//			}
//			c = j;
		//	c = (((((1/6) * j)*(j+1))* (2*j+1)));
			ds = 1/6 * j * (j+1) * (2*j+1);
			printf("%d",ds);
		}
		printf("Case #%d: %d\n",i+1,c); c = 0; b = 0;
	}
	
	return 0;
}

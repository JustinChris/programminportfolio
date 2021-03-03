#include <stdio.h>

struct data {
	long long int num1;
	long long int num2;
	long long int idx;
};
	

int main() {
	int t;
	scanf("%d",&t);
	for (int i = 0; i < t;i++) {
		int n,index;
		scanf("%d",&n);
		struct data angka[1005];
		for (int j = 0; j < n;j++) {
			scanf("%lld",&angka[j].num1);
			angka[j].idx = j;
		}
		
		for (int j = 0; j < n-1;j++) {
			for(int k = 0; k < n-j-1;k++) {
				if (angka[k].num1 > angka[k+1].num1) {
					struct data tamp = angka[k];
					angka[k] = angka[k+1];
					angka[k+1] = tamp;
				}
			}
		}
		
		index = 1;
		angka[0].num2 = index;
		for (int k = 1; k < n;k++) {
			if (angka[k].num1 == angka[k-1].num1) {
				angka[k].num2 = index;
			}else {
				index++;
				angka[k].num2 = index;
			}
		}
		
		for (int j = 0; j < n-1;j++) {
			for (int k = 0; k < n-j-1;k++) {
				if (angka[k].idx > angka[k+1].idx) {
					struct data tamp = angka[k];
					angka[k] = angka[k+1];
					angka[k+1] = tamp;
				}
			}
		}
		printf("Case #%d:",i+1);
		for (int j = 0; j < n;j++) {
			printf(" %lld",angka[j].num2);
		}
		printf("\n");
	}
	return 0;
}

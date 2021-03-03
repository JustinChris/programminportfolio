#include <stdio.h>

void prima(int arr[],int x) {
	int idx = 0;
	for (int i = 2; idx <= x; i++) {
		int flag = 1;
		for (int j = 2; j*j <= i;j++) {
			if (i % j == 0) {
				flag = 0;break;
			}
		}
		if (flag == 1) {
			int temp = i;
			while (temp > 10) {
				temp = temp%10;
			}
			arr[idx] = temp;
			idx++;
		}
	}
}

int main() {
	int t;
	scanf("%d",&t);
	for (int i = 0; i < t;i++) {
		int n;
		scanf("%d",&n);
		int barisN = n *(n+1) /2;
		int bilPrima[barisN];
		printf("Case #%d:\n",i+1);
		prima(bilPrima,barisN);
		int pos = 0;
		for(int j=0; j<n; j++) {                        
			for(int k=0; k<j+1; k++) {
				printf("%d", bilPrima[pos]);
				pos++;
			}
			printf("\n");
		}
	}
	
	return 0;
}



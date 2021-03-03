#include <stdio.h>

int main() {
	int m,n,count = 0,counts = 0;
	char Arr[10000];
	FILE *in = fopen("testdata.in","r");
	fscanf(in,"%d %d\n",&m,&n);
	fscanf(in,"%s",Arr);
//	for (int i = 0; i < m; i++) {
		for (int j = 0 ;j < m;j++) {
			if (Arr[j] == '1') {
				count++;
			}else {
				count = 0;
			}
			if (count == n) {
				counts++;
			}
		}
		printf("%d\n",counts);
//	}
	return 0;
}

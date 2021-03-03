#include <stdio.h>
#include <string.h>

struct data {
	char nama[50];
	char tree[50];
};

int main() {
	int t,n;
	struct data plant[150];
	FILE *in = fopen("testdata.in","r");
	fscanf(in,"%d\n",&n);
	for (int i = 0; i < n; i++) {
		fscanf(in,"%[^#]#%[^\n]\n",&plant[i].nama,&plant[i].tree);
	}
	fscanf(in,"%d\n",&t);
	for (int i = 0; i < t;i++){
		int flag = 0;
		char tampung[60];
		fscanf(in,"%s\n",&tampung);
		printf("Case #%d: ",i+1);
		for (int j = 0; j < n;j++){
			if (strcmp(tampung,plant[j].nama) == 0){
				printf("%s",plant[j].tree);
				flag = 1;
			}
		}
		if (flag == 0) {
			printf("N/A");
		}
		printf("\n");
	}
	return 0;
}

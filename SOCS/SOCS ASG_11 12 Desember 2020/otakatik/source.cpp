#include <stdio.h>
#include <string.h>

struct data {
	char depan[50];
	char belakang[50];
};

int main() {
	struct data tree[150];
	FILE *in = fopen("testdata.txt","r");
	int n;
	fscanf(in,"%d\n",&n);
	for (int i = 0; i < n; i++) {
		fscanf(in,"%[^#]#%[^\n]\n",tree[i].depan,tree[i].belakang);
	}
	int t;
	
	char tampung[100];
	fscanf(in,"%d",&t);
	for (int i = 0; i < t;i++) {
		int flag = 0;
		fscanf(in,"%s\n",tampung);
		for (int j = 0; j < n;j++) {	
			if(strcmp(tampung,tree[j].depan) == 0) {
				printf("%s\n",tree[j].belakang);
				flag = 1;
			}
		}
		if (flag == 0) {
			printf("N/A\n");
		}
	}
}

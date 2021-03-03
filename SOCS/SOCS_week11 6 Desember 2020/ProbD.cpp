#include <stdio.h>
#include <string.h>

struct data {
	char sword[100];
	char oword[100];
};

int main() {
	FILE *in = fopen("testdata.in","r");
	int n,t;
	struct data word[150];
	fscanf(in,"%d\n",&n);
	for (int i = 0; i < n; i++){
		fscanf(in,"%[^#]#%s\n",word[i].sword,word[i].oword);
	}
	fscanf(in,"%d",&t);
	char tampung[200];
	char output[300];
	int d = 0;
	for (int j = 0; j < t;j++){
		printf("Case #%d:\n",j+1);
		char x='\0';
		while (x != '\n') {
			fscanf(in,"%s%c",&tampung,&x);
			for (int k = 0; k < n;k++) {
				if (strcmp(tampung,word[k].sword) == 0) {
					strcpy(tampung,word[k].oword);
				}
			}
			printf("%s%c",tampung,x);
		}
	}
	return 0;
}

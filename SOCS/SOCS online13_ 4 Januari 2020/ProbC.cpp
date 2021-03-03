#include <stdio.h>
#include <string.h>

struct data {
	char ID[20];
	char name[50];
};
struct data profile[105];


int main() {
	FILE *in = fopen("testdata.in","r");
	int n;
	fscanf(in,"%d\n",&n);
	for (int i = 0; i < n;i++) {
		fscanf(in,"%s %s\n",profile[i].ID,profile[i].name);
	}
	int t;
	int flag = 0;
	char IDplh[12];
	fscanf(in,"%d\n",&t);
	for (int i = 0; i < t;i++) {
		fscanf(in,"%s\n",IDplh);
		for (int j = 0; j < n;j++) {
			if (strcmp(IDplh,profile[j].ID) == 0){
				printf("Case #%d: %s\n",i+1,profile[j].name);
				flag = 1;
			}
		}
		if (flag == 0) {
			printf("Case #%d: N/A\n",i+1);
		}
		flag = 0;
		
	}
	return 0;
}

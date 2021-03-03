#include <stdio.h>
#include <string.h>

int main() {
	FILE *in = fopen("testdata.in","r");
	int n,m;
	int t;
	fscanf(in,"%d %d",&n,&m);
	fgetc(in);
	char tampung[105][105][105];
	
	for (int i = 0 ; i < n; i++) {
		for (int j = 0; j < m;j++) {
			fscanf(in,"%[^\n]",tampung[i][j]);
			fgetc(in);
			if (strcmp(tampung[i][j],"#") == 0) {
				break;
			}
		}
	}
	fscanf(in,"%d\n",&t);
	for (int i = t-1; i < n;i++) {
		for (int j = 0; j < m;j++) {
			if (strcmp(tampung[i][j],"#") != 0) {
				printf("%s\n",tampung[i][j]);
			}else {
				break;
			}
		}
		break;
	}
	fclose(in);
	return 0;
}

#include <stdio.h>

int main() {
	FILE *in = fopen("testdata.in", "r");
	int t;
	int n,m;
	fscanf(in, "%d\n", &t);
	for (int i=1; i<=t; i++) {
		int xmin=1000,ymin=1000,xmax=-1,ymax=-1;
		fscanf(in, "%d %d\n",&n,&m);
		char matrix[n+1][m+1];
		for(int j=0; j<n; j++) {
			for(int k=0; k<m; k++){
				if(k==m-1) {
					fscanf(in,"%c\n",&matrix[j][k]);
				}
				else {
					fscanf(in,"%c",&matrix[j][k]);
				}
				if(matrix[j][k]!='.') {
					if(k<xmin) {
						xmin=k;
					}
					if(k>xmax) {
						xmax=k;
					}
					if(j<ymin) {
						ymin=j;
					}
					if(j>ymax) {
						ymax=j;
					}
				}
			}	
		}
		printf("Case #%d:\n", i);
		printf("%d %d\n", ymax-ymin+1, xmax-xmin+1);
		for(int awal=ymin; awal<=ymax; awal++) {
			for(int awal2=xmin; awal2<=xmax; awal2++) {
				printf("%c", matrix[awal][awal2]);
			}
			printf("\n");
		}
	}
	return 0;
}

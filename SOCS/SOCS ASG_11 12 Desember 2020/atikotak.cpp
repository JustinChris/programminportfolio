#include <stdio.h>
#include <string.h>

int main(){
	FILE *in = fopen("testdata.txt", "r");
	int n, m;
	fscanf(in, "%d %d\n", &n, &m);
	char tampung[101][101][101];
	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			fscanf(in, "%[^\n]\n", tampung[i][j]);
			if(strcmp(tampung[i][j],"#")==0) {
				break;
			}
		}
	}
	int K;
	fscanf(in, "%d", &K);
	for(int i=K-1;i<n;i++) {
		for(int j=0;j<m;j++) {	
			if(strcmp(tampung[i][j],"#")!=0) {
				printf("%s\n", tampung[i][j]);
			}
			else{
				break;
			}
		}
		break;
	}
	return 0;
}

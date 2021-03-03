#include <stdio.h>

int main() {
	int d = 0;
	int n,m;
	scanf("%d %d",&n,&m);
	char path[n][m];
	for (int i = 0; i < n; i++){
		for(int j = 0; j < m;j++){
			scanf("%c",&path[i][j]);
			if (path[i][j] == '.'){
				d++;
			}
		}
	}
	printf("%d\n",d+1);
	return 0;
}

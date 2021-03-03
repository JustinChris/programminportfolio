#include <stdio.h>

int main() {
	int N, M, star = 0;
	scanf("%d %d",&N,&M);
	char tempat[N+1][M+1];
	for (int i = 0; i < N; i++){
		for (int j = 0; j < M; j++){
			scanf(" %c",&tempat[i][j]);
		}
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			if(i-1>=0 && j-1>=0 && i+1<N && j+1<M){
				if(tempat[i][j] == '*' && tempat[i+1][j] == '*' && tempat[i][j+1] == '*' && tempat[i-1][j] == '*' && tempat[i][j-1] == '*'){
					star++;
				}
			}
		}
	}
	printf("%d\n", star);
	
	
	
	return 0;
}

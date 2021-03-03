#include <stdio.h>

char map[100][100];
int sum = 0;

void floodFill(int x, int y, int N, int M) {
	if (x < 0 || y < 0 || x > N || y > M) return;
	
	if (map[x][y] == '#') {
		map[x][y] = '+';
		
		floodFill(x,y+1,N,M);
		floodFill(x,y-1,N,M);
		floodFill(x-1,y,N,M);
		floodFill(x+1,y,N,M);
		floodFill(x+1,y+1,N,M);
		floodFill(x+1,y-1,N,M);
		floodFill(x-1,y-1,N,M);
		floodFill(x-1,y+1,N,M);
	}
	
}



void count (int N, int M) {
	for (int i = 0; i<N;i++) {
		for (int j = 0; j < M;j++) {
			if (map[i][j] == '#') {
				sum+=1;
				floodFill(i,j,N,M);
			}
		}
	}
}




int main() {
	
	int N, M;
	scanf("%d %d",&N,&M);
	
	for (int i = 0; i < N;i++) {
		scanf("%s",&map[i]);
	}
	
	count(N,M);
	
	printf("%d\n",sum);
	
	
	return 0;
}

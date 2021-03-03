#include <string.h>
#include <stdio.h>

int x[] = {-1,-1,-1,0,0,1,1,1};
int y[] = {-1,0,1,-1,1,-1,0,1};

bool searchGrid(const char grid[][105], char str[], int ROW, int COL, int n){
	
	if (grid[ROW][COL] != str[0]){
		return false;
	}
	
	int len = strlen(str);
	
	if (len != n){
		return false;
	}

	for (int dir = 0; dir < 8; dir++) {
		
		int k;
		int rd = ROW +x[dir];
		int cd = COL + y[dir];
		
		for (k = 1; k < len; k++) {
		
			if (rd >= n || rd < 0 || cd >= n || cd < 0)
				break;
		
		
			if (grid[rd][cd] != str[k])
				break;
		
			rd += x[dir];
			cd += y[dir];
		}
		
			if (k == len){
				return true;
		}
	}
	return false;
}


bool patternSearch(char grid[][105], char str[],int n){
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n;j++) {
			if (searchGrid(grid,str,i,j,n)) {
				return true;
			}
		}
	}
	return false;
}


int main() {
	int n;
	char str[35];
	
	scanf("%d",&n);
	char grid[105][105];
	scanf("%s",str);
	
	for (int i = 0; i < n; i++) {
		scanf("%s",grid[i]);
	}
	
	if (patternSearch(grid,str,n)) {
		printf("YES\n");
	}else {
		printf("NO\n");
	}
	
	
	return 0;
}

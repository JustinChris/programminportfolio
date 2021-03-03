#include<stdio.h>

char map[105][105];
//8 Possible movement : diagonally, vertically and horizontally
const int row[8]={-1, -1, 0, 1, 1, 1, 0, -1};
const int col[8]={0, 1, 1, 1, 0, -1, -1, -1};

//floodfill algorithm
void change(int i,int j,int n,int m){
	//invalid current position
    if(i < 1 || i > n || j < 1 || j > m)
        return;
    if(map[i][j] == '#'){ //this mean that it hasn't been changed
    	//or is part of the island
        map[i][j] = '.'; //signs that it has been visited
        for(int k=0;k<8;k++)	//visit other 8 direction
            change(i + row[k], j + col[k], n, m);
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    getchar();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)
            scanf("%c", &map[i][j]);
        getchar();
    }

    int island = 0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(map[i][j] == '#'){
                island += 1;
                change(i,j,n,m);
            }
    printf("%d\n",island);
    return 0;
}
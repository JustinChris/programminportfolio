#include<stdio.h>

void flag(int x,int y){
	if(x == 0)
		return;

	flag(x-1,y);

	for(int i=1;i<=y;i++){
		for(int j=1;j<=i*x;j++)
				printf("%d",x);
		printf("\n");
	}
	
	flag(x-1,y);
}
int main(){
	int n,m;
	scanf("%d %d%*c",&n,&m);
	flag(n,m);
	return 0;
}
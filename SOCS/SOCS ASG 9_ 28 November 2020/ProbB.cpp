#include <stdio.h>

void str(int n,char a[]) {
	if (n == 0 || n == 1){
		printf("%c",a[n]);
	}
	else {
		str(n-1,a),str(n-2,a);
	}
}


int main() {
	int t;
	scanf("%d",&t);
	for (int i = 0;i < t; i++){
		int n;
		char a[2];
		scanf("%d %c %c",&n,&a[0],&a[1]);
		printf("Case #%d: ",i+1);
		str(n,a);
		printf("\n");
	}
	
	return 0;
}

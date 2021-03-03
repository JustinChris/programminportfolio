#include <stdio.h>

int eq(int d,int s){
	if (d == 0 && s != 0){
		return 0;
	}else if (d != 0 && s == 0){
		return 0;
	}else {
		return 2*d + 3*s + eq(d-1,s) + eq(d,s-1);
	}
}

int main() {
	int m,n;
	scanf("%d %d",&m,&n);
	printf("%d\n",eq(m,n));
	return 0;
}

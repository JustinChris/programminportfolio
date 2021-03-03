#include <stdio.h>
int result;

int A(int a,int b){
	if (a == 0){
		return b+1;
	}else if (a > 0 && b == 0){
		return A(a-1,1);
	}else {
		return A(a-1,A(a,b-1));
	}
}

int main() {
	int m,n,result;
	scanf("%d %d",&m,&n);
	result = A(m,n);
	printf("result: %d\n",result);
	return 0;
}

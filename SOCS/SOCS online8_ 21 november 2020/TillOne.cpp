#include <stdio.h>

int formula(int d) {
	if (d == 1){
		return 1;
	}else if (d % 2 != 0){
		return formula(d-1) + formula(d+1);
	}
	if (d % 2 == 0){
		return formula(d/2);
	}
}

int main() {
	int t,n,res;
	scanf("%d",&t);
	for (int i = 0;i<t;i++){
		scanf("%d",&n);
		res = formula(n);
		printf("Case #%d: %d\n",i+1, res);
	}
	return 0;
}

#include <stdio.h>
int arr_memo[10000];

int jo(int d){
	if (d == 0){
		return 2;
	}if(d == 1){
		return 1;
	}if (arr_memo[d] != 0){
		return arr_memo[d];
	}else{
		return arr_memo[d] = jo(d-2) + jo(d-1) + 1;
	}	
}

int main() {
	int t,n,tamp;
	scanf("%d",&t);
	for (int i = 0;i<t;i++){
		scanf("%d",&n);
		tamp = jo(n);
		printf("Case #%d: %d\n",i+1,tamp);
	}
	return 0;
}

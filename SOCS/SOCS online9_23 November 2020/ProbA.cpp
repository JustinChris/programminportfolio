#include <stdio.h>


int sum(int jum, int *arr){
	if (jum <= 0){
		return 0;
	}
	else {
		return sum(jum-1,arr) + arr[jum-1];
	}
}
int main() {
	int t,n;
	int A[100000];
	int hasil;
	
	scanf("%d",&t);
	for(int i = 0; i < t; i++){
		scanf("%d",&n);
		for(int j = 0; j < n;j++){
			scanf("%d",&A[j]);
		}
		 hasil = sum(n,A);
		 printf("Case #%d: %d\n",i+1,hasil);
	}
	return 0;
}

#include <stdio.h>
#include <math.h>

int main (){
	int t,n,m,hasil = 0;
	scanf("%d",&t);
	for (int i = 0; i < t;i++){
		scanf("%d %d",&n,&m);
		for (int j = n-1; j < m; j++) {
			hasil += pow(2,j);
		}
		printf("Case #%d: %d\n",i+1,hasil);
		hasil = 0;
	}
	return 0;
}

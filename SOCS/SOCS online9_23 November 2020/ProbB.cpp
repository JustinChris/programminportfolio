#include <stdio.h>

int fibo(int awal, int akhir, int n){
	if (n == 0) {
		return awal;
	}
	if (n == 1){
		return akhir;
	}else {
		return fibo(awal,akhir,n-1) + fibo(awal,akhir,n-2);
	}
}

int main() {
	int aw,ak,n,hasil;
	scanf("%d %d",&aw,&ak);
	scanf("%d",&n);
	hasil = fibo(aw,ak,n);
	printf("%d\n",hasil);
	return 0;
}

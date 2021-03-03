#include <stdio.h>

int max;

void angka(int n,int m){
	int kel3,kel4,kel5;
	
	if(n <= m) {
		kel3 = n * 3;
		angka(kel3,m);
		if(kel3 > max && kel3 <= m){
			max = kel3;
		}
		kel4 = n * 4;
		angka(kel4,m);
		if (kel4 > max && kel4 <= m){
			max = kel4;
		}
		kel5 = n * 5;
		angka(kel5,m);
		if (kel5 > max && kel5 <= m){
			max = kel5;
		}
	}
	return;
}

int main() {
	int T,x,l;
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		scanf("%d %d",&x,&l);
		max= 0;
		angka(x,l);
		printf("Case #%d: %d\n",i+1,max);
	}
	return 0;
}

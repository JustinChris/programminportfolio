#include <stdio.h>
int n;
int tamp[7];
bool cek[8];

void permutasi(int s){
	if (s == n) {
		for(int j = 0; j < n;j++){
			printf("%d",tamp[j]);
		}
		printf("\n");
		return;
	}
	
	for(int i = 1; i<=n; i++){
		if(!cek[i]){
			cek[i] = true;
			tamp[s] = i;
			permutasi(s+1);
			cek[i] = false;
		}
	}

}


int main () {
	int T;
	scanf("%d",&T);
	for (int i = 0; i < T;i++){
		scanf("%d",&n);
		printf("Case #%d:\n",i+1);
		permutasi(0);
	}
}

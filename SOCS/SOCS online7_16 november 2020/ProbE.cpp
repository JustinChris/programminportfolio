#include <stdio.h>
int t,n;
long long int hasil;
int A[10],tamp[100];
bool cek[100];

void permutasi(int s){
	if (s == n) {
		long long int jum = 0;
		for(int j = 0; j < n;j++){
			jum = (jum*10) + A[tamp[j]];
		}
		hasil += jum;
		return;
	}
	
	for(int i = 0; i<n; i++){
		if(!cek[i]){
			cek[i] = true;
			tamp[s] = i;
			permutasi(s+1);
			cek[i] = false;
		}
	}
	return;
}



int main() {
	scanf("%d",&t);
	for (int i = 0; i < t; i++){
		scanf("%d",&n);
		for (int j = 0; j < n; j++){
			scanf("%d",&A[j]);
		} 
		hasil = 0;
		permutasi(0);
		printf("Case #%d: %lld\n",i+1,hasil);
	}
	return 0;
}

#include <stdio.h>

long long int fibo(long long int n){
	long long int f[n+2];
	f[1] = 1;
	f[2] = 1;
	for(int i = 3; i <= n; i++){
		f[i] = f[i-1] + f[i-2];
	}
	return f[n];
}

int main() {
	int T,L,R;
	scanf("%d",&T);
	for (int i = 0; i < T; i++){
		scanf("%d %d",&L,&R);
		int total = 0;
		long long int temp = 0;
		for (int j = L; j <= R; j++){
			temp = fibo(j);
			while(temp > 0){
				total += temp%10;
				temp /= 10;
			}
		}
		printf("Case #%d: %d\n",i+1, total);
	}
	
	return 0;
}

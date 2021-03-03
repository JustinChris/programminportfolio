#include <stdio.h>

int N;
long long quad[76];
long long mod = 1000000007;

long long F(int x) {
	// base case
	if(x == 1 || x == 2) return 0;
	if(x == 3 || x == 4) return 1;

	// if the value of F(x) has been calculated
	// then simply return the value
	// no need to recalculate
	if(quad[x] != -1) return quad[x];

	quad[x] = (F(x - 1) + F(x - 2) + F(x - 3) + F(x - 4)) % mod; 
	return quad[x];
}

int main() {
	scanf("%d", &N);

	for(int i = 0; i <= N; i++) {
		// temporary value
		// if quad[x] = -1 
		//that means the value of F(x) has not been calculated
		quad[i] = -1; 
	}

	printf("%d", F(N));
	
	return 0;
}
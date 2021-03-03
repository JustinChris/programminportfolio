#include <stdio.h>

int N;
int quad[76];
int mod = 1000000007;

int main() {
	int N;
	scanf("%d", &N);

	// base case
	quad[1] = quad[2] = 0;
	quad[3] = quad[4] = 1;

	for(int i = 4; i <= N; i++) {
		quad[i] = 0;
		// add quad[i] with quad[i - 1], quad[i - 2], quad[i - 3] and quad[i - 4]
		for(int j = 1; j <= 4; j++) { 
			quad[i] += quad[i - j];
			quad[i] %= mod; // don't forget the modulo
		}
	}

	printf("%d", quad[N]);

	return 0;
}
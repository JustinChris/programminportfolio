#include <stdio.h>

int T, X, Y;
int calc[1000001];
int mod = 1e9 + 7;

int S(int x, int y) {
	// if y = 0 return 2 ^ x
	if(y == 0) return calc[x];

	int ans = 0;
	// finding factors
	// loop only up to sqrt(x)
	for(int i = 1; i * i <= x; i++) {
		if(x % i == 0) { // if i is a factor of n
			if(i == x / i) { // example: 3 = 9 / 3
				ans += S(i, y - 1);
				ans %= mod;
			}
			else {
				// add both i and x / i
				ans += S(i, y - 1);
				ans %= mod;

				ans += S(x / i, y - 1);
				ans %= mod;
			}
		}	
	}

	return ans;
}	

int main() {
	// compute all possible value of 2^X
	calc[0] = 1; // 2^0 = 1
	for(int i = 1; i <= 1000000; i++) {
		calc[i] = 2 * calc[i - 1];
		calc[i] %= mod;
	}

	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &X, &Y);
		printf("%d\n", S(X, Y));
	}

	return 0;
}
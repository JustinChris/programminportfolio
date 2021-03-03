#include <stdio.h>

long long mod = 1000000007;

long long quad(int N) {
    if(N == 1 || N == 2) return 0;
    if(N == 3 || N == 4) return 1;

    return (quad(N - 1) + quad(N - 2) + quad(N - 3) + quad(N - 4)) % mod;    
}

int main() {
    long long N; 
    scanf("%lld", &N);

    printf("%lld\n", quad(N));

    return 0;
}
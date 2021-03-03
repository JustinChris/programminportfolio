#include <stdio.h>
#include <math.h>

int main()
{
int T;
scanf("%d", &T);
int N, M, sum;

for(int j = 1; j <= T; j++)
{
scanf("%d", &N);
scanf("%d", &M);
sum = 0;

for(int i = N-1; i < M; i++)
{
sum += pow(2,i);
}

printf("Case #%d: %d\n", j, sum);
}
return 0;
}

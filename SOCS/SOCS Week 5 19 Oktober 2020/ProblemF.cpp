#include<stdio.h>

int main(){
    int T; 
    long long int count = 0;
    long long int N;
    long long int A[1001]={0};
    int x;
    scanf("%d", &T);
    for (int i = 0; i < T; i++){
        scanf("%lld", &N);
        for (int j = 0; j < N; j++){
            scanf("%d", &x);
            A[x]++;
        }
        for (int j = 1; j <= 1000; j++){
            if(A[j]>=3){
                count += A[j]*(A[j]-1)*(A[j]-2)/6;
            }
            A[j] = 0;
        }
        printf("Case #%d: %lld\n", 1+i, count);
        count = 0;
    }
    return 0;
}

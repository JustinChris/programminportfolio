#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
    long long unsigned int a, b, *c, *d, e, g;
    char *c1, *c2;
    long long int f;
    double x, y, z;
    int zz, chy;
    long long unsigned int *ch;
    scanf("%d", &zz);
    for(int i = 0; i < zz; i++){
        chy = 0;
        ch = (long long unsigned int *)malloc(chy*sizeof(long long unsigned int));
        scanf("%llu", &a);
        b = a;
        for(int j = 2; j < sqrt(a)+1; j++){
            while(b%j == 0){
                chy += 1;
                ch = (long long unsigned int*)realloc(ch, chy*sizeof(long long unsigned int));
                ch[chy-1] = j;
                b = b/j;
            }
        }
        if(b > 2){
            chy += 1;
                ch = (long long unsigned int*)realloc(ch, chy * sizeof(long long unsigned int));
                ch[chy-1] = b;
        }
        printf("Case #%d:", i+1);
        d = (long long unsigned int *)malloc(chy * sizeof(long long unsigned int));
        e = 0;
        f = 0;
        for(int k = 0; k < chy; k++){
            if(ch[k-1] != ch[k]){
                if(k != 0){
                    printf(" ^ %llu *", d[f]);
                    f += 1;
                }
                printf(" %llu", ch[k]);
                d[f] = 1;
            } else {
                d[f] += 1;
            }
        }
        printf(" ^ %llu\n", d[f]);
        printf("\n");
        free(ch);
        free(c);
        free(d);    
    }
}

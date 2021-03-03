#include<stdio.h>
#include<string.h>


int formula(char s[50], char d[50], int ls, int ld){
    if(ld < 0){
        return 1;
    }
    if(ls < 0){ 
        return 0;
    }
    if(s[ls] == d[ld]){
        return formula(s, d, ls - 1, ld - 1) + formula(s, d, ls - 1, ld); 
    }
    else{
        return formula(s, d, ls - 1, ld); 
    }
}

int main() {
    char atas[50], bawah[50];
    int t, panjangS, panjangK;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%s",atas);
        scanf("%s",bawah);
        panjangS = strlen(atas) - 1;
        panjangK = strlen(bawah) - 1;
        printf("Case #%d: %d\n", i, formula(atas, bawah, panjangS, panjangK));
    }
}

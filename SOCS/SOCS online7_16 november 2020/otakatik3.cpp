#include<stdio.h>
#include<string.h>


int a(char x[40],char y[40],int stringx, int stringy ){
    
    if(stringx < 0){
        return 0;
    }
    if(stringy < 0){
        return 1;
    }
    if(x[stringx] == y[stringy]){
        return a(x, y, stringx - 1, stringy - 1) + a(x, y, stringx - 1, stringy);
        
        
    }
    else{
        return a(x, y, stringx - 1, stringy);
        
    }
}
int main(){

    char x[40], y[40];
	int t, hasil, stringx, stringy;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        scanf("%s", x);
        scanf("%s", y);
        stringx = strlen(x)-1;
        stringy = strlen(y)-1;
        hasil = a(x, y, stringx, stringy);
        printf("Case #%d: %d\n", i+1, hasil);
        hasil =0;
    }
}

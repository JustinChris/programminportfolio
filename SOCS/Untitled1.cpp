#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

bool comp(const int a[], const int b[], int n)
{
    int total = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n;j++){

            if (b[i] == pow(a[j],2)){
                total++;
                break;
            }
        }
    }
    if (total == n){
        total = 0;
        return 1;
    }else {
        total = 0;
        return 0;
    }
  
}

int main() {
	bool determine;
	int a[8] = {121, 144, -19, -161, -19, -144, 19, 11};
    int b[8] = {14641, 20736, 361, 25921, 361, 20736, 361, 121};
    printf("%d",strlen(a));
	determine = comp(a,b,8);
	if (determine){
		printf("True\n");
	}else {
		printf("false\n");
	}
}

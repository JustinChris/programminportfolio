#include <stdio.h>

int main() {
	int a,b,c,d;
	int hasil1,hasil2;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	hasil1 = a * b;
	hasil2 = c - d;
	
	if(hasil1 == hasil2){
		printf("True\n");
	}else {
		printf("False\n");
	}
	return 0;
}

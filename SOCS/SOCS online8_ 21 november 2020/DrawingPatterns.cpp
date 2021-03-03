#include <stdio.h>
#include <math.h>

	
void formula(int n, int x, int y){
	if(n > 0) {
		formula(n-1,x+pow(2,n-2),y);
		int asterisk = 1;
		for (int i = 1; i < n;i++){
			asterisk *= 2;
		}
		for (int i = 0; i < x; i++){
			printf(" ");
		}
		for (int i = 0; i < asterisk; i++){
			printf("*");
		}
		printf("\n");
		formula(n-1,x,y);
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int d = 0;
	int s = 0;
	formula(n+1,d,s);
	return 0;
}


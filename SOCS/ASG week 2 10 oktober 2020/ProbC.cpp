#include <stdio.h>

int main() {
	double A,B,C;
	double x;
	scanf("%lf %lf %lf",&A,&B,&C);
	
	x = (C * -1) / A;
	
	printf("%.2lf\n",x);
	
	return 0;
}

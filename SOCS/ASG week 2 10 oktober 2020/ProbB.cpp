#include <stdio.h>

int main() {
	double T,Ut,Ua;
	double result[3];
	double final;
	scanf("%lf %lf %lf",&T,&Ut,&Ua);
	
	result[0] = 0.2 * T;
	result[1] = 0.3 * Ut;
	result[3] = 0.5 * Ua;
	
	final = result[0] + result[1] + result[3];
	
	printf("%.2lf\n",final);
	
	return 0;
}

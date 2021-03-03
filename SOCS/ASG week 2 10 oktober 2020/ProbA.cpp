#include <stdio.h>

int main() {
	double N[100],P[100];
	double result[100];

	scanf("%lf %lf",&N[0],&P[0]);
	scanf("%lf %lf",&N[1],&P[1]);
	scanf("%lf %lf",&N[2],&P[2]);
	scanf("%lf %lf",&N[3],&P[3]);
	
	result[0] = 100/(100-N[0]) * P[0];
	result[1] = 100/(100-N[1]) * P[1];
	result[2] = 100/(100-N[2]) * P[2];
	result[3] = 100/(100-N[3]) * P[3];
	
	printf("$%.2lf\n",result[0]);
	printf("$%.2lf\n",result[1]);
	printf("$%.2lf\n",result[2]);
	printf("$%.2lf\n",result[3]);
	return 0;
}

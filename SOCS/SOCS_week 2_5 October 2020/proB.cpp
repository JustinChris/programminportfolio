#include <stdio.h>

int main() {
	double L,B,H;
	double Area1,Area2,result;
	
	scanf("%lf %lf %lf",&L,&B,&H);
	Area1 = B * H;
	Area2 = B * L * 3;
	result = Area1 + Area2;
	
	printf("%.3lf\n",result);
	return 0;
}

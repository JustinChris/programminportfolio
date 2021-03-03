#include <stdio.h>

int main() {
	int T = 3;
	double input[4];
	double A,B,result;
	
	scanf("%d",&T);
	for(int i = 0;i < T; i++) {
	scanf("%lf %lf",&A,&B);
	result = (A*B)/360;
	input[i]= result;
}
	printf("%.2lf\n",input[0]);
	printf("%.2lf\n",input[1]);
	printf("%.2lf\n",input[2]);

	return 0;
}

#include <stdio.h>
#include <math.h>

int main() {
	int A,B,C;
	double pi = 3.14159265359;
	double rAB,rr,Luas,rrs;
	scanf("%d %d %d",&A,&B,&C);
	//luas permukaan bola 4pi r^2
	//diagonal ruang balok
	rAB = sqrt( (A*A) + (B*B) );
	rr = sqrt( (C*C) + (rAB*rAB) );
	rrs = rr/2;
	Luas = 4 * pi * rrs * rrs;
	printf("%.2lf\n",Luas);
	return 0;
}

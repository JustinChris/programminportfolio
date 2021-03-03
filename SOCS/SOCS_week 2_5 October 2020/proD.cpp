#include <stdio.h>

int main() {
	int A,B,C,D;
	int A2,B3,B1,C1,C2;
	int n;
	
	scanf("%d %d %d %d",&A,&B,&C,&D);
	
	n = A + B + C;
	A2 = n - A - D;
	B3 = n - D - C;
	B1 = n - B3 - B;
	C1 = n - A - B1;
	C2 = n - A2 - B;
	
	printf("%d %d %d\n",A,A2,D);
	printf("%d %d %d\n",B1,B,B3);
	printf("%d %d %d\n",C1,C2,C);
	return 0;
}

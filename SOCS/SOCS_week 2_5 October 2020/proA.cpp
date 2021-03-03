#include <stdio.h>

int main() {
	long int A1,B1,C1,D1;
	long int A2,B2,C2,D2;
	long int A3,B3,C3,D3;
	long int result1,result2,result3;
	
	scanf("(%ld+%ld)x(%ld-%ld)\n",&A1,&B1,&C1,&D1);	
	scanf("(%ld+%ld)x(%ld-%ld)\n",&A2,&B2,&C2,&D2); 
	scanf("(%ld+%ld)x(%ld-%ld)",&A3,&B3,&C3,&D3);	
	
	result1 = (A1+B1) * (C1-D1);
	result2 = (A2+B2) * (C2-D2);
	result3 = (A3+B3) * (C3-D3);


	printf("%ld %ld %ld\n", result1, result2,result3);
	return 0;
}

#include <stdio.h>

int main() {
	int a,b;
	FILE *in = fopen("testdata.in","r");
	fscanf(in,"%d %d",&a,&b);
	printf("%d\n",a+b);
	
	return 0;
}

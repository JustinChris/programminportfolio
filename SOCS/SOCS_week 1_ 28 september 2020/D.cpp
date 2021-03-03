#include <stdio.h>

int main() {
	char x1[4];
	scanf("-%s-",x1);
	printf("-%c%c%c-\n",x1[2],x1[1],x1[0]);
	return 0;
}

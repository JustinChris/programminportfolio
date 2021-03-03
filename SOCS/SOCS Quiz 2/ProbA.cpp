#include <stdio.h>

int rec (int x) {
	if (x == 0) {
		return 0;
	}else {
		return rec(x-1) + 1;
	}
}

int main() {
	int x;
	scanf("%d",&x);
	printf("%d\n",rec(x));
	return 0;
}

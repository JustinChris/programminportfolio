#include <stdio.h>

int main() {
	char x1,x2,x3;
	
	scanf("%c %c %c",&x1,&x2,&x3);
	
	if (x1 < x2 && x2 < x3){
		printf("1 2 3\n");
	}else if (x1 < x3 && x3 < x2){
		printf("1 3 2\n");
	}else if (x2 < x3 && x3 < x1){
		printf("2 3 1\n");
	} else if (x2 < x1 && x1 < x3){
		printf("2 1 3\n");
	} else if (x3 < x1 && x1 < x2){
		printf("3 1 2\n");
	} else if (x3 < x2 && x2 < x1){
		printf("3 2 1\n");
	}
	

	
	return 0;
}

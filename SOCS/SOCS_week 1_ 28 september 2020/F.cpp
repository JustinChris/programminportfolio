#include <stdio.h>

int main() {
	char x1[100];
	char x2[100];
	char x3[100];
	
	scanf("%[^\n]",x1); getchar();
	scanf("%[^\n]",x2); getchar();
	scanf("%[^\n]",x3); getchar();
	
	printf("  %c\n",x1[0]);
	printf(" %c %c\n",x2[0], x1[2]);
	printf("%c %c %c\n",x3[0],x2[2],x1[4]);
	printf(" %c %c\n",x3[2], x2[4]);
	printf("  %c\n",x3[4]);
	return 0;
}

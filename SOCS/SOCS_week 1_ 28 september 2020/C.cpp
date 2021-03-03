#include<stdio.h>

int main() {
	char a[100];
	scanf("%[^\n]",&a);
	printf("#include <stdio.h>\n");
	printf("int main()\n");
	printf("{\n");
	printf("    printf(\"\%%s\\n\",\"%s\");\n",a);
	printf("    return 0;\n");
	printf("}\n");
	return 0;
}

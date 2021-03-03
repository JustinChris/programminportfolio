#include <stdio.h>
#include <string.h>

int main() {
	int n;
	char present[1005][105];
	char placeholder[105];
	int index;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%s %d",placeholder,&index);
		strcpy(present[index-1],placeholder);
	}
	for (int i = 0; i < n; i++) {
		printf("Lecturer #%d: %s\n",i+1,present[i]);
	}
	
	return 0;
}

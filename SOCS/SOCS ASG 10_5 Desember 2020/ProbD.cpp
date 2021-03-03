#include <stdio.h>
#include <string.h>

struct data {
	char s[30];
	char t[30];
};

int main() {
	int n,count = 0;
	struct data nama[1000];
	scanf("%d",&n);
	for (int i = 0; i < n; i++){
		scanf("%s %s",&nama[i].s,&nama[i].t);
	}
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n;j++){
			if (strcmp(nama[i].s,nama[j].s) == 0 && strcmp(nama[i].t,nama[j].t) == 0){
				count++;
			}
		}
	}
	printf("%d\n",count);
	return 0;
}

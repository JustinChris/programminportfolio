#include <string.h>
#include <stdio.h>

struct data {
	char username[105];
	char domain[105];
};

int main() {
	int n;
	int total = 0;
	char filter[105];
	struct data email[1005];
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%[^@]@%[^\n]",email[i].username,email[i].domain);
	}
	scanf("%s",filter);
	for (int i = 0; i < n;i++) {
		if (strcmp (email[i].domain,filter) == 0) {
			total++;
		}
	}
	printf("%d\n",total);
	return 0;
}

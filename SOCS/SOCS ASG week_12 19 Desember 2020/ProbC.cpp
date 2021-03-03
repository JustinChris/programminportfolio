#include <stdio.h>
#include <string.h>

struct data {
	char nama[150];
};


int main() {
	int t,n;
	int count = 0;
	scanf("%d",&t);
	for(int i = 0; i < t;i++) {
		scanf("%d",&n);
		struct data profile[n+5];
		for (int j =0; j< n;j++) {
			scanf("%s",&profile[j].nama);
		}
		for (int j = 0; j < n-1;j++) {
			for (int k = 0;k < n-j-1;k++) {
				if (strcmp(profile[k].nama,profile[k+1].nama) > 0) {
					struct data temp = profile[k];
					profile[k] = profile[k+1];
					profile[k+1] = temp;
				}
			}
		}
		
		for (int s = 0; s < n;s++) {
			if (strcmp(profile[s].nama,profile[s+1].nama) != 0) {
				count++;
			}
		}
		printf("Case #%d: %d\n",i+1,count); count = 0;
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

struct data {
	char nama[60];
	int num;
};
struct data arr[105];
struct data temp[105];

int main() {
	int t,n;
	scanf("%d",&t);
	for (int i = 0; i < t;i++) {
		scanf("%d",&n);
		for(int j = 0; j < n;j++) {
			scanf("%[^#]#%d",&arr[j].nama,&arr[j].num);
		}
		for (int i1 = 0; i1 < n;i1++) {
			for (int i2 = 0; i2 < n;i2++) {
				if (arr[i1].num < arr[i2].num) {
					struct data tamp = arr[i1];
					arr[i1] = arr[i2];
					arr[i2] = tamp;
					
				}else if (arr[i1].num == arr[i2].num) {
					if (strcmp(arr[i1].nama,arr[i2].nama) < 0) {
						struct data tamp = arr[i1];
						arr[i1] = arr[i2];
						arr[i2] = tamp;
						
					}
				}
			}
		}
		printf("Case #%d:",i+1);
		for (int k = 0; k < n;k++) {
			printf("%s - %d",arr[k].nama,arr[k].num);
		}
		printf("\n");
	}
	
	return 0;
}

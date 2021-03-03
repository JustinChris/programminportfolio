#include <stdio.h>

struct data {
	char nama[20];
	int grup;
};

int main() {
	int t,n;
	struct data member[300];
	scanf("%d",&t);
	for (int i = 0; i < t; i++){
	int count[300] = {0};
		scanf("%d",&n);
		for (int j = 0; j < n;j++){
			scanf("%s %d",member[j].nama,&member[j].grup);
			count[member[j].grup]++;
		}
		printf("Case #%d:\n",i+1);
		for (int j = 1;j<201;j++){
			if (count[j]!= 0){
				printf("Group %d(%d):\n",j,count[j]);
				for (int k = 0;k < n;k++){
					if (member[k].grup == j) {
						printf("%s\n",member[k].nama);
					}
				}
			}
		}
	}
	return 0;
}

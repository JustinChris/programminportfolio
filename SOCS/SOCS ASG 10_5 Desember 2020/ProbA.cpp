#include <stdio.h>

struct pelanggan {
	int DD;
	int MM;
	char nama[255];
	int bought;
};

int main() {
	int t,d,s = 0,a = 0;
	int day,month;
	struct pelanggan query[5000];
	scanf("%d",&t);
	int n,m;
	for (int i = 0; i < t; i++){
		scanf("%d %d",&n,&m);
		for (int j = 0;j < n;j++){
			scanf("%s %d/%d %d",&query[j].nama,&query[j].DD,&query[j].MM,&query[j].bought);
		}
		scanf("%d",&d);
		printf("Case #%d:\n",i+1);
		for (int k = 0; k < d;k++){
			scanf("%d/%d",&day,&month);
			for (int j = 0; j < n;j++){
				if (day == query[j].DD && month == query[j].MM && query[j].bought >= m){
					printf("%s\n",query[j].nama);
					s++;
				}
			}
			if (s == 0){
				printf("No one\n");
			}
			s = 0;
		}
		a = 0;
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

struct data {
	char nama[60];
	int num;
};
struct data sort[100];
struct data temp[100];

int main() {
	int t;
	scanf("%d",&t);
	for (int i =0; i < t;i++) {
		int n;
		scanf("%d",&n);
		for(int j = 0;j < n;j++) {
			scanf("%[^#]#%d",sort[j].nama,&sort[j].num);getchar();
		}
		for (int j = 0;j < n;j++) {
			for (int k = 0; k < n;k++) {
				if(sort[j].num > sort[k].num) {
					temp[j].num = sort[j].num;
					strcpy(temp[j].nama,sort[j].nama);
					
					sort[j].num = sort[k].num;
					strcpy(sort[j].nama,sort[k].nama);
					
					sort[k].num = temp[j].num;
					strcpy(sort[k].nama,temp[j].nama);	
				}
			}
		}
		printf("Case #%d:\n",i+1);
		for (int d = 0;d < n;d++) {
			printf("%s - %d",sort[d].nama,sort[d].num);
		}
		printf("\n");
	}
	return 0;
}

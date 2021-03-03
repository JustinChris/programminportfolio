#include <stdio.h>
#include <string.h>

struct ganda {
	char nama[200];
	int lebih;
}data[2000];

int main() {
	int n,count = 0;
	scanf("%d",&n);
	for (int i = 0; i < n;i++){
		scanf("%s",data[i].nama);
		
		for (int j = 0; j <= i; j++){
			if (data[j].lebih != 0 && strcmp(data[j].nama,data[i].nama) == 0)break;
			else if (strcmp(data[j].nama,data[i].nama) == 0 && i != j && data[j].lebih == 0){
				data[j].lebih = 1;
				count++;
				break;
			}
		}
	}
	printf("You have %d duplicate name(s).\n",count);
	return 0;
}

#include <stdio.h>
#include <string.h>

struct data {
	char code[7];
	char name[50];
};
struct data plants[1000];

void merge (int l, int r) {
	for (int i = 0; i < r;i++) {
		for (int j = 0; j < r-i;j++) {
			
			if (strcmp(plants[j].name,plants[j+1].name) > 0){
				struct data swap = plants[j];
				plants[j] = plants[j + 1];
                plants[j + 1] = swap;
			}
		}
	}
}



int main() {
	FILE *in = fopen("testdata.in","r");
	int n = 0;
	int total;
	fscanf(in,"%d\n",&total);
	while(!feof(in)) {
		fscanf(in,"%[^#]#%[^\n]\n",plants[n].code,plants[n].name);
		n++;
	}
	merge(0,n-1);
	
	int d = 0;

	for (int i = 0; i < total;i++) {
		printf("%s %s\n",plants[i].code,plants[i].name);
	}
	return 0;
}

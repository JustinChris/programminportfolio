#include <stdio.h>
#include <string.h>

struct data {
	char city[1005];
	float temp;
	float conv;
	char metric;
};


int main() {
	FILE *in = fopen("testdata.in","r");
	struct data cities[1001];
	int d = 0;
	while (!feof(in)) {
		fscanf(in,"%[^#]#%f#%C\n",cities[d].city,&cities[d].temp,&cities[d].metric);
		d++;
	}
	
	for (int i = 0; i < d;i++) {
		if (cities[i].metric == 'F') {
			cities[i].conv = ((cities[i].temp - 32) * 5/9);
		}else {
			cities[i].conv = cities[i].temp;
		}
	}
	
	for (int i = 0;i < d-1;i++) {
		for (int j = 0; j < d-i-1;j++) {
			if(cities[j].conv > cities[j+1].conv) {
				struct data tampung = cities[j];
				cities[j] = cities[j+1];
				cities[j+1] = tampung;
			}else if (cities[j].conv == cities[j+1].conv) {
				if (strcmp(cities[j].city,cities[j+1].city) > 0) {
					struct data tampung = cities[j];
					cities[j] = cities[j+1];
					cities[j+1] = tampung;
				}
			}
		}
	}
	
	for (int i = 0; i < d;i++) {
		printf("%s is %.2f%C\n",cities[i].city,cities[i].temp,cities[i].metric);
	}
	
	return 0;
}

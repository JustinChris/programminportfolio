#include <stdio.h>
#include <string.h>

struct data {
	char title[1002];
	char artist[1002];
	int view;
};
struct data profile[101];

int main() {
	FILE *in;
	in = fopen("testdata.in", "r");
	int n = 0;
	while(!feof(in)) {
		fscanf(in,"%[^#]#%[^#]#%d\n", profile[n].title , profile[n].artist, &profile[n].view);
		n++;
	}
	for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (profile[j].view < profile[j + 1].view) {
                struct data temp = profile[j];
                profile[j] = profile[j + 1];
                profile[j + 1] = temp;
            }
            if(profile[j].view == profile[j+1].view) {
            	if(strcmp(profile[j].title,profile[j+1].title) > 0) {
            		struct data temp = profile[j];
                	profile[j] = profile[j + 1];
               		profile[j + 1] = temp;
				}
			}
        }
    }
	for(int j = 0; j < n; j++) {
		printf("%s by %s - %d\n",profile[j].title , profile[j].artist , profile[j].view);
	}
	fclose(in);
	return 0;
}


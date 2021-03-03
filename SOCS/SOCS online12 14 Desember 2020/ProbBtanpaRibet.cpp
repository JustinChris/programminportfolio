#include <stdio.h>
#include <string.h>

struct data {
	char title[1005];
	char artist[1005];
	int view;
};
struct data profile[101];
struct data temp[101];

int main() {
	FILE *in;
	in = fopen("testdata.txt","r");
	int d = 0;
	while(!feof(in)) {
		fscanf(in,"%[^#]#%[^#]#%d",profile[d].title,profile[d].artist,&profile[d].view);
		fgetc(in);
		d++;
	}
	for(int i = 0; i < d;i++) {
		for(int j = 0; j < d; j++) {
			if (profile[i].view > profile[j].view) {
				
				temp[i].view = profile[j].view;
				strcpy(temp[i].title,profile[j].title);
				strcpy(temp[i].artist,profile[j].artist);
				
				profile[j].view = profile[i].view;
				strcpy(profile[j].title,profile[i].title);
				strcpy(profile[j].artist,profile[i].artist);
				
				profile[i].view = temp[i].view;
				strcpy(profile[i].title,temp[i].title);
				strcpy(profile[i].artist,temp[i].artist);
				
			}
			else if (profile[i].view == profile[j].view){
				
				if (strcmp(profile[i].title,profile[j].title) < 0) {
					
					temp[i].view = profile[j].view;
					strcpy(temp[i].title,profile[j].title);
					strcpy(temp[i].artist,profile[j].artist);
					
					profile[j].view = profile[i].view;
					strcpy(profile[j].title,profile[i].title);
					strcpy(profile[j].artist,profile[i].artist);
					
					profile[i].view = temp[i].view;
					strcpy(profile[i].title,temp[i].title);
					strcpy(profile[i].artist,temp[i].artist);
				}
			}
		}
	}
	
	for (int i = 0; i < d; i++) {
		printf("%s by %s - %d",profile[i].title,profile[i].artist,profile[i].view);
		printf("\n");
	}
	
	fclose(in);
	return 0;
}

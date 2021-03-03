#include <stdio.h>
#include <string.h>

struct data {
	char title[1000];
	char artist[1000];
	int view;
};

struct data video[101];

void merge (int l,int m,int r){
	int i,j,k;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	struct data left[n1];
	struct data right[n2];
	
	for (i = 0; i < n1; i++){
		left[i].view = video[l+i].view;
		strcpy(left[i].title,video[l+i].title);
		strcpy(left[i].artist,video[l+i].artist);
	}
	for (j = 0; j < n2;j++) {
		right[j].view = video[m+1+j].view;
		strcpy(right[j].title,video[m+1+j].title);
		strcpy(right[j].artist,video[m+1+j].artist);
	}
	i =0, j = 0, k = l;	
	while(i < n1 && j < n2) {
		if(left[i].view < right[j].view) {
			video[k].view = left[i].view;
			strcpy(video[k].title,left[i].title);
			strcpy(video[k].artist,left[i].artist);
			i++;
		}else if (left[i].view > right[j].view){
			video[k].view = right[j].view;
			strcpy(video[k].title,right[j].title);
			strcpy(video[k].artist,right[j].artist);
			j++;
		}else {
			if(strcmp(left[i].artist,right[j].artist) < 0) {
				video[k].view = left[i].view;
				strcpy(video[k].title,left[i].title);
				strcpy(video[k].artist,left[i].artist);
				i++;
			}
		}
		k++;
	}
	while (i < n1) {
		video[k].view = left[i].view;
		strcpy(video[k].title,left[i].title);
		strcpy(video[k].artist,left[i].artist);
		i++;
		k++;
	}
	while (j < n2) {
		video[k].view = left[j].view;
		strcpy(video[k].title,left[j].title);
		strcpy(video[k].artist,left[j].artist);
		j++;
		k++;
	}
}

void mergesort (int l,int r) {
	if (l < r) {	
		int mid = (l+r)/2;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,mid,r);
	}
}

int main() {
	int d = 0;
	FILE *in = fopen("testdata.in","r");
	while(!feof(in)) {
		fscanf(in,"%[^#]#%[^#]#%d\n",video[d].title,video[d].artist,&video[d].view);
		d++;
	}
	mergesort(0,d-1);
	
	for (int i = d-1; i >= 0;i--) {
		printf("%s by %s - %d\n",video[i].title,video[i].artist,video[i].view);
	}
	
	return 0;
}

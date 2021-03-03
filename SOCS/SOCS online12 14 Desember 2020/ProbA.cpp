#include <stdio.h>
#include <string.h>

struct data {
	char nama[51];
	int num;
};
data profile[60];
data tamp[60];

void mergesort(int awal,int akhir) {
	if (awal == akhir) return;
	int mid = (akhir+awal)/2;
	mergesort(awal,mid);
	mergesort(mid+1,akhir);
	
	int pointerawal = awal;
	int pointerakhir = mid+1;
	int idx = 0;
	
	while (pointerawal <= mid && pointerakhir <= akhir) {
		if (profile[pointerawal].num > profile[pointerakhir].num) {
			tamp[idx].num = profile[pointerawal].num;
			strcpy(tamp[idx].nama,profile[pointerawal].nama);
			idx++;
			pointerawal++;
		}else if (profile[pointerawal].num < profile[pointerakhir].num) {
			tamp[idx].num = profile[pointerakhir].num;
			strcpy(tamp[idx].nama,profile[pointerakhir].nama);
			idx++;
			pointerakhir++;
		}
		else {
			if (strcmp(profile[pointerawal].nama,profile[pointerakhir].nama) < 0) {
				tamp[idx].num = profile[pointerawal].num;
				strcpy(tamp[idx].nama,profile[pointerawal].nama);
				idx++;
				pointerawal++;
			}
//			else if (strcmp(profile[pointerawal].nama,profile[pointerakhir].nama) > 0){
//				tamp[idx].num = profile[pointerakhir].num;
//				strcpy(tamp[idx].nama,profile[pointerakhir].nama);
//				idx++;
//				pointerakhir++;
//			}
		}
	}
	while(pointerawal <= mid) {
		tamp[idx].num = profile[pointerawal].num;
		strcpy(tamp[idx].nama,profile[pointerawal].nama);
		idx++;
		pointerawal++;
	}
	while(pointerakhir <= akhir) {
		tamp[idx].num = profile[pointerakhir].num;
		strcpy(tamp[idx].nama,profile[pointerakhir].nama);
		idx++;
		pointerakhir++;
	}
	
	for (int i = awal; i < akhir;i++) {
		profile[i].num = tamp[i-awal].num;
		strcpy(profile[i].nama,tamp[i-awal].nama);
	}
}

int main() {
	int t,n;
	scanf("%d",&t);
	for (int i = 0; i < t; i++) {
		scanf("%d",&n);
		for (int j = 0; j < n; j++) {
			scanf("%[^#]#%d",profile[j].nama,&profile[j].num);getchar();
		}
		mergesort(0,n-1);
		printf("Case #%d:\n",i+1);
		for (int k = 0; k < n;k++) {
			printf("%s - %d\n",profile[k].nama,profile[k].num);
		}
	}
	return 0;
}

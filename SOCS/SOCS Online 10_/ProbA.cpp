#include <stdio.h>

struct data {
	int tanggal;
	int bulan;
	int tahun;
	char nama[50];
	char alamat[50];
};

int main() {
	int n,q,an[150] = {0};
	int x,d;
	scanf("%d",&n);
	struct data mahasiswa[200];
	for (int i = 0; i < n; i++){
		scanf("%d",&x);
		scanf("%d %d %d",&mahasiswa[x].tanggal,&mahasiswa[x].bulan,&mahasiswa[x].tahun);
		scanf("%s",mahasiswa[x].nama);
		scanf("%s",mahasiswa[x].alamat);
		an[x] = 1;
	}
	scanf("%d",&q);
	for (int i = 0;i < q; i++) {
//		scanf("%d",&an[i]);
		scanf("%d",&d);
		if (an[d] == 0){
			printf("No data found!\n");
		} else {
			printf("%d. %s was born on %d/%d/%d and live at %s\n",d,mahasiswa[d].nama,mahasiswa[d].tanggal,mahasiswa[d].bulan,mahasiswa[d].tahun,mahasiswa[d].alamat);
		}
	}
//	for (int i = 1; i <=q;i++) {
//		if (mahasiswa[an[i]].ID != 0){
//			printf("%d. %s was born on %d/%d/%d and live at %s\n",mahasiswa[i].ID,mahasiswa[i].nama,mahasiswa[i].tanggal,mahasiswa[i].bulan,mahasiswa[i].tahun,mahasiswa[i].alamat);
//		}else {
//			printf("No data found!\n");
//		}
//	}
	return 0;
}

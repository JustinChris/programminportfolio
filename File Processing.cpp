#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char daftarbelanja[50][50];
int daftarbelanjaangka[100] = {0};
char namabaranginput[100];
int banyakbaranginput;
int banyakbarangout[100];
int i = 0;

bool ask = true;
int pilihan;
FILE *fop;
FILE *fcl;
	
struct data {
	char nama[30];
	char ID[15];
	int stok;
};
struct data produk[50];
struct data menu3[50];

void menus1 () {
	int s = 0;
	printf("\nMasukan Kode atau Nama Produk:\n");
	getchar();
	scanf("%[^\n]",namabaranginput);
	for (int k = 0;k < i;k++){
		if(strcmp(namabaranginput,produk[k].nama) == 0 || strcmp(namabaranginput,produk[k].ID) == 0){
			printf("Masukan Jumlah Pembelian:\n");
			scanf("%d",&banyakbaranginput);
			if (banyakbaranginput > produk[k].stok){
				printf("Stok tidak cukup");
			}else {
				produk[k].stok -= banyakbaranginput;
				strcpy(daftarbelanja[s],namabaranginput);
				daftarbelanjaangka[s] = banyakbaranginput;
				s++;
				printf("Sukses Memasukkan Barang");
			}
		}
	}
}

void menus2 () {
	fcl = fopen("jualan@.dat","w");
	int d = 0;
	if (fcl == NULL){
		printf("data can't be created\n");
		exit(1);
	}
	for (int k = 0;k < i;k++){
		if (strcmp(daftarbelanja[d],produk[k].nama) == 0 || strcmp(daftarbelanja[d],produk[k].ID) == 0){
			fprintf(fcl,"%s_%d_%d\n",produk[k].ID,produk[k].stok,banyakbaranginput);
		}
	}
	printf("Mencetak Data Pembelian Anda...");
	fclose(fcl);
}

void menus3 () {
	int a = 0;
	fcl = fopen("jualan@.dat","r");
	while (!feof(fcl)) {
		fscanf(fcl,"%[^_]_%d_%d\n",menu3[a].ID,&menu3[a].stok,&banyakbarangout[a]);
		a++;
	}
	for (int e = 0; e < a;e++){
		printf("%s  %d  %d\n",menu3[e].ID,menu3[e].stok,banyakbarangout[e]);
	}
	fclose(fcl);
}

void menus4 () {
	ask = false;
	fclose(fcl);
	fclose(fop);
	getchar();
}

int main() {
//	fcl = fopen("jualan@.dat","w");
	fop = fopen("database.txt","r");
	if (fop == NULL) {
		printf("Database Tidak Ditemukan");
	}else {
		while(!feof(fop)){
			fscanf(fop,"%[^#]#%[^#]#%d\n",produk[i].nama,produk[i].ID,&produk[i].stok);
			i++;
		}
		for(int j = 0; j < i;j++){
			printf("%-20s %-20s %-5d\n",produk[j].nama,produk[j].ID,produk[j].stok);
		}
			printf("\nApa yang ingin anda lakukan:\n");
			printf("1. Masukkan Pembelian\n");
			printf("2. Tulis Data Pembelian\n");
			printf("3. Baca Data Pembelian\n");
			printf("4. Keluar\n");
		while (ask){
			printf("\nSilahkan Pilih Perintah:\n");
			scanf("%d",&pilihan);
			//---------------------------------------------------------------------- udah bisa sampe sini
			switch(pilihan){
				case 1: menus1(); break;
				case 2: menus2(); break;
				case 3: menus3(); break;
				case 4: menus4(); break;
				default: printf("Pilihan tidak ada");
			}
		}
		printf("Terima Kasih Telah Menggunakan Program Ini");
	}
	return 0;
}

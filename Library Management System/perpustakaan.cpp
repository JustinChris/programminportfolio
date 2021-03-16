#include <stdio.h>
#include <string.h>

struct perpustakaan {
	char nama[100];
	char kode[100];
	int qty;
};
struct perpustakaan buku[200];
int n = 0;
int mark;
bool ask = true;
FILE *in = fopen("data.txt","r");

void menu1() {
struct perpustakaan bukutemp[200];
	for (int i = 0;i < n; i++){
		for (int j = i+1 ;j < n;j++){
			if (strcmp(buku[i].nama,buku[j].nama) > 0) {
				
				strcpy(bukutemp[i].nama,buku[i].nama);
				strcpy(bukutemp[i].kode,buku[i].kode);
				bukutemp[i].qty = buku[i].qty;
				
				strcpy(buku[i].nama,buku[j].nama);
				strcpy(buku[i].kode,buku[j].kode);
				buku[i].qty = buku[j].qty;
				
				strcpy(buku[j].nama,bukutemp[i].nama);
				strcpy(buku[j].kode,bukutemp[i].kode);
				buku[j].qty = bukutemp[i].qty;
			}
		}
	}
	printf("\nNama Buku \t\t\tKode Buku \t Quantity\n\n");
	for (int i = 0; i < n;i++){
		printf("%-30s %-20s %-5d",buku[i].nama,buku[i].kode,buku[i].qty);
		printf("\n");
	}
}

void menu2() {
	char inputbuku[200];
	char pilih;
	int flag = 0;
	printf("Masukan Nama atau Kode Buku\n");
	getchar();
	scanf("%[^\n]",inputbuku); 
	for (int i = 0; i < n; i++){
		if (strcmp(inputbuku,buku[i].nama) == 0 || strcmp(inputbuku,buku[i].kode) == 0 && buku[i].qty > 0){
			printf("Buku %s Stock Tersedia\n",buku[i].nama);
			printf("Apakah Anda Ingin Meminjam Buku ini? (y/n)\n");
			getchar();
			scanf("%c",&pilih);
			if (pilih == 'y'){
				mark = i;
				printf("Buku dipinjam!\n");
			}else if (pilih == 'n') {
				printf("Buku Tidak dipinjam\n");
			}
			flag = 1;
			break;
		}
	}
	if (flag == 0) {
		printf("Maaf Buku yang Anda Cari Tidak Tersedia\n");
	}
}

void menu3(int first,int last) {
	int i, j, pivot;
	struct perpustakaan bukutemp[200];
	
	if (first < last) {
		pivot = first;
		i = first;
		j = last;
		
		while (i < j) {
			while(buku[i].qty <= buku[pivot].qty && i < last){
				i++;
			}
			while (buku[j].qty > buku[pivot].qty){
				j--;
			}
			if (i < j) {
				strcpy(bukutemp[i].nama,buku[i].nama);
				strcpy(bukutemp[i].kode,buku[i].kode);
				bukutemp[i].qty = buku[i].qty;
				
				strcpy(buku[i].nama,buku[j].nama);
				strcpy(buku[i].kode,buku[j].kode);
				buku[i].qty = buku[j].qty;
				
				strcpy(buku[j].nama,bukutemp[i].nama);
				strcpy(buku[j].kode,bukutemp[i].kode);
				buku[j].qty = bukutemp[i].qty;
			}
		}
		bukutemp[i].qty = buku[pivot].qty;
		strcpy(bukutemp[i].nama,buku[pivot].nama);
		strcpy(bukutemp[i].kode,buku[pivot].kode);
		
		buku[pivot].qty = buku[j].qty;
		strcpy(buku[pivot].nama,buku[j].nama);
		strcpy(buku[pivot].kode,buku[j].kode);
		
		buku[j].qty = bukutemp[i].qty;
		strcpy(buku[j].nama,bukutemp[i].nama);
		strcpy(buku[j].kode,bukutemp[i].kode);
		
		menu3(first,j-1);
		menu3(j+1,last);
	}
}
void printmenu3() {
	printf("\nNama Buku \t\t\tKode Buku \t Quantity\n\n");
	for (int k = 0; k < n;k++){
		printf("%-30s %-20s %-5d",buku[k].nama,buku[k].kode,buku[k].qty);
		printf("\n");
	}
}

void menu4() {
FILE *out = fopen("data.txt","w");
	for (int i = 0; i < n; i++){
		if (i == mark) {
			fprintf(out,"%s#%s#%d\n",buku[i].nama,buku[i].kode,buku[i].qty - 1);
		}else {
			fprintf(out,"%s#%s#%d\n",buku[i].nama,buku[i].kode,buku[i].qty);
		}
	}
	ask = false;
	fclose(out);
	fclose(in);
}


int main() {
	int pilihan;
	while (!feof(in)) {
		fscanf(in,"%[^#]#%[^#]#%d\n",buku[n].nama,buku[n].kode,&buku[n].qty);
		n++;
	}
	printf("----------Perpustakaan Digital----------\n");
	printf("\nSilahkan Pilih Menu\n");
	printf("1. Keluarkan Pilihan Buku dari A-Z\n");
	printf("2. Cari Buku\n");
	printf("3. Keluarkan Pilihan Buku Berdasarkan Quantity\n");
	printf("4. Pinjam Buku\n");
	
	while (ask){
		printf("\nMasukan Perintah!\n");
		scanf("%d",&pilihan);
		switch (pilihan) {
			case 1: menu1(); break;
			case 2: menu2(); break;
			case 3: menu3(0,n-1); printmenu3(); break;
			case 4: menu4(); break;
			default: printf("Menu Tidak Terdaftar\n"); break;
		}
	}
	return 0;
}

#include <stdio.h>
FILE *saldo;
int global = 0;
struct Data
{
long long int uang;
long long int rekening;
char nama[250];
}data[50];
void setor()
{
	long long int transfer;
	saldo = fopen("data.csv", "w");
	printf("Masukkan jumlah yang ingin anda setor:\n");
	scanf("%lld", &transfer);
	data[global].rekening=data[global].uang+transfer;
	fprintf(saldo,"%s,%lld",data[global].nama,data[global].rekening);
	fclose(saldo);
	printf("Berhasil\n");
}
void tariktunai()
{
	long long int tarik;
	saldo=fopen("data.csv","w");
	printf("Jumlah dana yang akan diambil:\n");
	scanf("%lld",&tarik);
	if(tarik>data[global].uang)
	{
		printf("Saldo anda tidak mencukupi. Penarikan dana tidak bisa dilakukan\n\n");
	}
	else
	{
		data[global].rekening=data[global].uang-tarik;
		fprintf(saldo,"%s,%lld",data[global].nama,data[global].rekening);
		fclose(saldo);
		printf("Penarikan dana berhasil\n");
	}
}
void ceksaldo()
{
	printf("Saldo: Rp. %lld,-\n",data[global].uang);
}
void keluar()
{
	printf("Terima Kasih Yth. %s!\n",data[global].nama);
}
void menu()
{
	printf("=========WELCOME TO BANK JAGO==========\n");
	printf("1. Setor Uang\n");
	printf("2. Tarik Dana\n");
	printf("3. Cek Saldo\n");
	printf("4. Keluar\n");
	printf("Pilih transaksi:\n");
	int pilih; scanf("%d",&pilih);
	switch(pilih){
		case 1:
			setor();
			menu();
			break;
		case 2:
			tariktunai();
			menu();
			break;
		case 3:
			ceksaldo();
			menu();
			break;
		case 4:
			keluar();
			return;
		default:
			printf("NULL\n");
			menu();
			break;
	}
}
int main()
{
	saldo=fopen("data.csv","r");
	fscanf(saldo,"%[^#]#%lld",data[global].nama,&data[global].uang);
	printf("Selamat Datang Yth. %s!\n Ada yang bisa kami bantu?\n",data[global].nama);
	fclose(saldo);
	menu();
	return 0;
}

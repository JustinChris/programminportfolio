#include<stdio.h>

int main(){
int N,S,A,B,C;
int sisi,hasil;

scanf("%d %d %d %d %d",&N,&S,&A,&B,&C);
sisi = A/S;
sisi = sisi * (B/S);
sisi = sisi * (C/S);

hasil = (N + sisi - 1) / sisi;

printf("%d\n",hasil);

	return 0;
}

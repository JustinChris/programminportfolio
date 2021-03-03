#include <stdio.h>

int main(){
	int l, m, rook = 0, bishop = 0, knight = 0, baris, kolom, baris1, kolom1, a, b, n;
	
	scanf("%d %d", &l, &m);
	
	int papan[l+1][l+1]={0};
	for(int i=1;i<=m;i++){
		scanf("%d %d", &baris, &kolom);getchar();
		papan[baris][kolom] = 1;
	}
	scanf("%d", &n);
	for(int i=1;i<=n;i++){
		scanf("%d %d", &baris1, &kolom1);getchar();
		a = baris1;
		b = kolom1;
		do{
		//bishop
		// kiri atas
			if(papan[a][b]==1){
			bishop++;break;
			}
			else{
				a--;b--;
			}		
		}while(a>=1&&b>=1);
		a = baris1;
		b = kolom1;
		do{
			//kiri bawah
			if(papan[a][b]==1){
				bishop++;break;
			}
			else{
				a--;b++;
			}
		}while(a>=1&&b<=l);
		a = baris1;
		b = kolom1;
		do{
			//kanan atas
			if(papan[a][b]==1){
				bishop++;break;
			}
			else{
				a++;b++;
			}
		}while(a<=l&&b<=l);
		a = baris1;
		b = kolom1;
		do{
			//kanan bawah
			if(papan[a][b]==1){
				bishop++;break;
			}
			else{
				a++;b--;
			}
		}while(a<=l&&b>=1);
		a = baris1;
		b = kolom1;
		//rook
		do{
			// rook atas
			if(papan[a][b]==1){
				rook++;break;
			}
			else{
				b--;
			}
		}while(b>=1);
		a = baris1;
		b = kolom1;
		do{
			// rook bawah
			if(papan[a][b]==1){
				rook++;break;
			}
			else{
				b++;
			}	
		}while(b<=l);
		a = baris1;
		b = kolom1;
		do{
			// rook kiri
			if(papan[a][b]==1){
				rook++;break;
			}
			else{
				a--;
			}
		}while(a>=1);
		a = baris1;
		b = kolom1;
		do{
			// rook kanan
			if(papan[a][b]==1){
				rook++;break;
			}
			else{
				a++;
			}
		}while(a<=l);
		a = baris1;
		b = kolom1;
		//knight
		//lebar atas kiri
		if(a-2>=1&&b-1>=1&&papan[a-2][b-1]==1){
			knight++;
		}
		//tinggi kiri atas
		if(a-1>=1&&b-2>=1&&papan[a-1][b-2]==1){
			knight++;
		}
		//lebar kiri bawah
		if(a-2>=1&&b+1<=l&&papan[a-2][b+1]==1){
			knight++;
		}
		//tinggi kiri bawah
		if(a-1>=1&&b+2<=l&&papan[a-1][b+2]==1){
			knight++;
		}
		//lebar atas kanan
		if(a+2<=l&&b-1>=1&&papan[a+2][b-1]==1){
			knight++;
		}
		//tinggi atas kanan
		if(a+1<=l&&b-2>=1&&papan[a+1][b-2]==1){
			knight++;
		}
		//lebar kanan bawah
		if(a+2<=l&&b+1<=l&&papan[a+2][b+1]==1){
			knight++;
		}
		//tinggi kanan bawah
		if(a+1<=l&&b+2<=l&&papan[a+1][b+2]==1){
			knight++;
		}
		if(rook>bishop&&rook>knight){
			printf("3\n");
		}
		else if(bishop>=rook&&bishop>knight){
			printf("2\n");
		}
		else if(knight>=rook&&knight>=bishop)
			printf("1\n");
		rook = 0;
		bishop = 0;
		knight = 0;
	}
	

	return 0;
}

#include<stdio.h>
#include<math.h>

int main(){
	
	int T;
	scanf("%d", &T);
	long long int N, y = 2, z = 0, x = 1;
	
	for(int i=0;i<T;i++){
		scanf("%lld", &N);
		printf("Case #%d: ", i+1);
		while(1){
			if(N==1){
				break;
			}
			while(N%y == 0){   // cek berapa kali faktor yang ad skrng brp kali pangkat
				N/=y;
				z++;
			}
			if(z != 0 && N != 1){   // buat ngeprint pangkat skrng
				printf("%d ^ %d * ", y, z); 
				z=0;
			}else if (z != 0 && N == 1){
				printf("%d ^ %d", y, z);
				z=0;
			}	
			while(1){  //buat cek kalo andai angka itunya prima ato g
			y++;x = 1;
			for(int j=2;j<=sqrt(y);j++){
			if(y%j == 0){
				x = 0;break;	
			}
			}	
			if(x == 0) continue;
			else break;
			
		}
		
	}
		printf("\n"); 
		y =2;
}
	
	
	
	return 0;
}

#include<stdio.h>

int main(){
	int cas;
	char kode[1000][10];
	char day[1000][10];
	int waktu[1000];
	int t;
	int firstPrint;
	scanf("%d ", &cas);
	for(int i = 0 ; i < cas ; i ++){
		scanf("%s\n", &kode[i]);
		scanf("%s\n", &day[i]);
		scanf("%d", &waktu[i]);
	}
	scanf("%d", &t);
	for(int i = 0 ; i < t ; i ++){
		scanf("%d", &firstPrint);
		printf("Query #%d:\n",i+1);
		printf("Code: %s\n", kode[firstPrint-1]);
		printf("Day: %s\n", day[firstPrint-1]);
		if(waktu[firstPrint-1] < 10) {
			printf("Time: 0%d:00\n", waktu[firstPrint-1]);
		}
		else {
			printf("Time: %d:00\n", waktu[firstPrint-1]);	
		}
	}
}

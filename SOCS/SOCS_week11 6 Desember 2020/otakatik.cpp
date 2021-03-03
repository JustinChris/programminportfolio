#include <stdio.h>
#include <string.h>

int main() {
	FILE *in = fopen("testdata.txt","r");
	int t;
	int a,d;
	fscanf(in,"%d\n",&t);
	for (int i = 0; i < t;i++){
	int k;
	char s[1000];
		fscanf(in,"%d\n",&k);
		fscanf(in,"%[^\n]",&s);
		for (int j = 0; j < strlen(s); j++){
			if (s[j] == '0') {
				if (('O' -k) < 65) {
					a = 'O' - 64;
					d = k - a;				//O
					s[j] = 90 - d;
				}else {
					s[j] = 'O' - k;	
				}
			}else if (s[j] == '1'){
				if (('I' - k) < 65) {
					a = 'I' - 64;
					d = k - a;				//I
					s[j] = 90 - d;
				}else {
					s[j] = 'I' - k;	
				}
			}else if (s[j] == '3'){
				if (('E' - k) < 65) {
					a = 'E' - 64;
					d = k - a;				//E
					s[j] = 90 - d;
				}else {
					s[j] = 'E' - k;	
				}
			}else if (s[j] == '4') {
				if (('A' - k) < 65) {
					a = 'A' - 64;
					d = k - a;				//A
					s[j] = 90 - d;
				}else {
					s[j] = 'A' - k;	
				}
			}else if (s[j] == '5') {
				if (('S' - k) < 65) {
					a = 'S' - 64;
					d = k - a;				//S
					s[j] = 90 - d;
				}else {
					s[j] = 'S' - k;	
				}
			}else if (s[j] == '6') {
				if (('G' - k) < 65) {
					a = 'G' - 64;
					d = k - a;				//G
					s[j] = 90 - d;
				}else {
					s[j] = 'G' - k;	
				}
			}else if (s[j] == '7') {
				if (('T' - k) < 65) {
					a = 'T' - 64;
					d = k - a;				//T
					s[j] = 90 - d;
				}else {
					s[j] = 'T' - k;
				}
			}else if (s[j] == '8') {
				if (('B' - k) < 65) {
					a = 'B' - 64;
					d = k - a;				//B
					s[j] = 90 - d;
				}else {
					s[j] = 'B' - k;	
				}
			}else if (s[j] == 32) {
				s[j] = ' ';
			}else {
				if ((s[j] - k) < 65) {
					a = s[j] - 64;
					d = k - a;
					s[j] = 90 - d;
				}else {
					s[j] -= k;	
				}		
			}
		}
		printf("Case #%d: %s\n",i+1,s);
//		fclose(in);
	}
	return 0;
}

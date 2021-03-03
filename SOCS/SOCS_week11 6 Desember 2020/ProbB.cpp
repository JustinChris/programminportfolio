#include <stdio.h>

int main() {
	FILE *in = fopen("testdata.txt","r");
	int t;
	char x[100];
	
	fscanf(in,"%d",&t);
	for (int i = 0; i < t;i++){
		fscanf(in,"%s",&x);	
	}
	return 0;
}

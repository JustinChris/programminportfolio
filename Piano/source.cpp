#include <stdio.h>
#include <windows.h>

int main() {
	FILE *in = fopen("notes.txt","r");
	int n;
	double freq[500];
	char keys[500];
	while (!feof(in)) {
		fscanf(in,"%c %lf\n",&keys[n],&freq[n]);
		n++;
	}
	fclose(in);
	FILE *out = fopen("play.txt","r");
	char str[500];
	int p = 0;
	while(!feof(out)) {
		fscanf(out,"%c\n",&str[p]);
		p++;
	}
	

	while(true) {
		char ch = getchar();
		if (ch == '=') {
			for (int i = 0; i < p;i++) {
				for (int j = 0; j < n;j++) {
					if (str[i] == keys[j]) {
						Beep(freq[j],500);
					}
				}
			}
		}
		for (int i = 0; i < n;i++) {
			if (ch == keys[i]){
				Beep(freq[i],500);
			}
		}
	}
	return 0;
}


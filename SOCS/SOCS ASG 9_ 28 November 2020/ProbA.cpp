#include <stdio.h>
#include <string.h>

void swap (char *strng,int awal,int akhir){
	char tamp;
	
	if (awal >= akhir){
		return;
	}
	tamp = *(strng+awal);
	*(strng + awal) = *(strng + akhir);
	*(strng + akhir) = tamp;
	
	swap(strng,++awal,--akhir);	
}

int main() {
	int t;
	char str[1000];
	scanf("%d",&t);getchar();
	for(int i = 0; i < t; i++){
		scanf("%[^\n]",str);
		getchar();
		swap(str,0,strlen(str) - 1);
		printf("Case #%d: %s\n",i+1,str);
	}
	
	return 0;
}

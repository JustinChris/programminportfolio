#include <stdio.h>

int main() {
	int n;
	int flag = 1;
	int count = 0;
	char nama1[1000];
	char nama2[1000];
	char nama3[1000];
	
	scanf("%d",&n);
	for (int i = 0; i < n;i++){
		scanf("%s",&nama1[i]);
	}
	
	for (int j = 0; j < n;j++){
		nama2[j] = nama1[j];
		nama3[j] = 0;
	}
	
	for(int i=0;i<n; i++) {
    	for(int j=0;j<n;j++) {

      		if(nama1[i]==nama2[j]) {
        		nama3[j]=flag;
        		flag++;
			}
    	}
    	flag=1;
	}
	
	for(int i=0; i<n; i++) {
		if(nama3[i]==2) {
			count++;
		}
	}

printf("You have %d duplicate name(s).\n", count);
	
	return 0;
}

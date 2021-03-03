#include<stdio.h>

int main(){
	int n,t;
	char arr[11][12] = {"a", "unu","du", "tri", "kvar", "kvin", "ses", "sep", "ok", "nau"};
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &t);
		int m = 0, x = 0;
		int num[10] = {};
		while(t > 0){
			x++;
			num[x] = t%10;				
			t/=10;
		}
		printf("Case #%d:", i+1);
		for(int j = x; j > 0; j--)
		{
			if(num[j] == 1){
				switch(j) {
					case 4: printf(" mil");break;
					case 3: printf(" cent");break;
					case 2: printf(" dek");break;
					case 1: printf(" unu");break;
				}
			}
			
			else if(num[j] > 0){
			printf(" %s", arr[num[j]]);
				switch(j) {
					case 2: printf("dek");break;
					case 3: printf("cent");break;
					case 4: printf(" mil");break;
				}	
			}
		}
		
		printf("\n");
	}
	
}

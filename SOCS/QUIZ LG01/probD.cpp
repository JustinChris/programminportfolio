#include <stdio.h>

int main(){
	int T,N;
	char str[100];
	scanf("%d",&T);
	for (int i = 0; i < T;i++){
		scanf("%d %s",&N,&str);
		if(str[0] == 'a' || str[0] == 'e' || str[0] == 'i' || str[0] == 'o' || str[0] == 'u' || str[0] == 'y'){
			printf("Case #%d: j'%s\n",i+1,str);
		}else if (str[0] == 'h'&& str[1] == 'a' ||str[0] == 'h' && str[1] == 'e' || str[0] == 'h' && str[1] == 'i' ||str[0] == 'h'&&str[1] == 'o' ||str[0] == 'h' && str[1] == 'u' || str[0] == 'h' && str[1] == 'y'){
			printf("Case #%d: j'%s\n",i+1,str);
		}else {
			printf("Case #%d: je %s\n",i+1,str);
		}
	}
	
	return 0;
}

#include <stdio.h>

int main() {
	
	int a,x,y, s = 0, d, g;
	scanf("%d",&a);
	
	
	for(int i = 0; i < a;i++){
		scanf("%d %d",&g,&y);
		x = g;
		do {
			d = x/y;
			x = d + (x%y);
			s = s + d;
		}while(x>=y);
		printf("Case #%d: %d\n",i+1,s+g);
		d = 0; x = 0; s = 0;
	}
	
	return 0;
}

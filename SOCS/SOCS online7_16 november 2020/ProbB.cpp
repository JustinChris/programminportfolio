#include <stdio.h>

int step = 0;

int formula (int a){
	if (a == 0) {
		return 1;
	}else if (a == 1){
		return 2;
	}else {
		if (a % 3 == 0){
			return formula(a - a/3) + 1;
		}else {
			step++;
			return formula(a-1) + a + formula(a-2) + 1;
		}
	}
}
int langkah (int d){
	if (d == 0 || d == 1 || d == 2){
		return 0;
	}else if ( d == 3){
		return 1;
	}else if (d==4){
		return 2;
	}if (d%3 != 0){
		return langkah(d-1) + langkah(d-2);
	}else if (d%3==0 && d!=3){
		return langkah(d-(d/3));
	}
}

int main() {
	int T,result,n;
	scanf("%d",&T);
	for (int i = 0; i < T; i++){
		scanf("%d",&n);
		result = formula(n);
		step = langkah(n);
		printf("Case #%d:",i+1);
		printf(" %d %d\n",result,step);
	}
	return 0;
}

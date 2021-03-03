#include <stdio.h>

struct data {
	char nama[200];
	int sal1;
	int sal2;
	int sal3;
};
struct data emp[200];

void swap (int s1,int s2){
	for (int i = s1, j = s2;i <= j;i++,j--){
		int temp1 = emp[i].sal1;
		emp[i].sal1 = emp[j].sal1;
		emp[j].sal1 = temp1;
		
		int temp2 = emp[i].sal2;
		emp[i].sal2 = emp[j].sal2;
		emp[j].sal2 = temp2;
		
		int temp3 = emp[i].sal3;
		emp[i].sal3 = emp[j].sal3;
		emp[j].sal3 = temp3;
	}
}

void swap2 (int s3,int s4){
	for (int i = s3; i <= s4;i++){
		int temp1 = emp[i].sal1;
		int temp2 = emp[i].sal2;
		int temp3 = emp[i].sal3;
		emp[i].sal1 = temp3;
		emp[i].sal2 = temp1;
		emp[i].sal3 = temp2;
		
	}
}

int main () {
	int t,n,q;
	int ch[200];
	int s1[200];
	int s2[200];
	scanf("%d",&t);
	for (int i = 0;i < t;i++){
		scanf("%d %d",&n,&q);
		for (int j = 1;j <= n;j++){
			scanf("%s %d %d %d",emp[j].nama,&emp[j].sal1,&emp[j].sal2,&emp[j].sal3);
		}
		for (int k = 1; k <= q;k++) {
			scanf("%d %d %d",&ch[k],&s1[k],&s2[k]);
		}
		for (int l = q; l >= 1; l--){
			if (ch[l] == 1) {
				swap(s1[l],s2[l]);
			}
			if (ch[l] == 2){
				swap2(s1[l],s2[l]);
			}
		}
		printf("Case #%d:\n",i+1);
		for (int h = 1; h <= n;h++){
			printf("%s %d\n",emp[h].nama,emp[h].sal3);
		}
	}
	
	
	
	
	
	return 0;
}

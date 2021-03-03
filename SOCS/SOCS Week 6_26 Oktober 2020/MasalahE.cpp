#include <stdio.h>
#include <string.h>

int main() {
	long long int T,pjgA,pjgB; 
	char A[30],B[30];
	scanf("%d",&T);
	for (int i = 1; i <= T;i++){
		scanf("%s %s",A,B);
		getchar();
		pjgA = strlen(A);
		pjgB = strlen(B);
		long long int c=0,d=1;
		long long int tampungA = 0,tampungB = 0;
		printf("Case #%d: ",i);
		
		if (pjgA > pjgB){
			for (int j = 0; j < pjgA - pjgB; j++){
				tampungA = A[j] - '0';
				printf("%lld",tampungA);
				c++;
			}
			for(int k = 0; k < pjgB; k++){
				tampungA = A[c] - '0';
				tampungB = B[k] - '0';
				printf("%lld", (tampungA + tampungB) % 10);
				c++;
			}
		}else if (pjgA < pjgB){
			for(int j = 0 ; j < pjgB -pjgA;j++){
				tampungB = B[j] - '0';
				printf("%lld",tampungB);
				c++;
			}
			for(int k = 0; k < pjgA; k++){
				tampungA = A[k] - '0';
				tampungB = B[c] - '0';
				printf("%lld",(tampungA + tampungB) % 10);
				c++;
			}
		}else {
			for (int j = 0;j < pjgA;j++){
				tampungA = A[j] - '0';
				tampungB = B[j] - '0';
				if((tampungA + tampungB) % 10 == 0 && d == 0){
					printf("%lld",(tampungA + tampungB) % 10);
				}else if((tampungA + tampungB) % 10 != 0) {
					printf("%lld",(tampungA+tampungB) % 10);
					d = 0;
				}
			}
			if (d == 1) {
				printf("0");
			}
		}
		printf("\n");
	}
	return 0;
}

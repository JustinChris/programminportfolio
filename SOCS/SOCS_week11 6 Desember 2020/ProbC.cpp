#include <stdio.h>

int main() {
	int t,n,x[105],count = 0,keliling = 0;
	
	FILE *in = fopen("testdata.in","r");
	
	fscanf(in,"%d\n",&t);
	
	for (int i = 0; i < t;i++){
		fscanf(in,"%d\n",&n);
		for(int j = 0;j < n;j++){
			fscanf(in,"%d",&x[j]);
		}
		
		for (int j = 0;j < n;j++) {
			count += 4*x[j];
            keliling += (8 * x[j] - (4 * (x[j] - 1)));
            if (j!= n-1) {
                if (x[j] >= x[j+1]) {
                    keliling -= 4 * x[j+1];    
                }
                else {
                    keliling -= 4 * x[j];
                }
            }
        }
        printf("Case #%d: %d %d\n",i+1,keliling,count); keliling = 0; count = 0;
	}
	return 0;
}

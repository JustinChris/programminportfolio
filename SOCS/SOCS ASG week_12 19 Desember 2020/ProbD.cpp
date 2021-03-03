#include <stdio.h>

int find (int num[],int l,int r, int x, int flag) {
	int index = -1;
	while (l <= r) {
		int m = (l+r)/2;
		if (num[m] == x) {
			index = m;
			if (flag == 0) {
				r = m-1;
			}
			else {
				l = m+1;
			}
		}else if (num[m] < x) {
			l = m+1;
		}else {
			r = m-1;
		}
	}
	return index;
}

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	int x[n],A[m];
	for (int i =0; i < n;i++) {
		scanf("%d",&x[i]);
	}
	int d;
	for (int j = 0; j < m;j++) {
		scanf("%d",&d);
		int l = find(x, 0, n-1,d,0);
		int r = find(x, 0, n-1,d,1);
		if (l != -1) {
			l++;
		}
		if (r != -1) {
			r++;
		}
		printf("%d %d\n",l,r);
	}
	return 0;
}

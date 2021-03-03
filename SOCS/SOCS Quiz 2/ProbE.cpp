#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[],int l,int r, int x){
	if (r >= l) {
		int mid = (l+r)/2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l,mid-1,x);
		return binarySearch(arr,mid+1,r,x);
	}
	return -1;
}

int main() {
	int N,M,A[100000],X[100000];
	scanf("%d",&N);
	scanf("%d",&M);
	int i,j;
	for(i=0;i<N;i++) {
    	scanf("%d",&A[i]);
	}
	for(i=0;i<M;i++) {
	    scanf("%d",&X[i]);
	}
	for(i=0;i<M;i++) {
//	    int p=-2;
//	    for(j=0;j<N;j++) {
//	        if(A[j]>=X[i]) {
//	            p=j;
//	            break;
//	        }
//	    }
	    printf("%d\n",binarySearch(A,0,N-1,X[i]));
	}
}

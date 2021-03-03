#include <stdio.h>

long long int binarySearch(long long int arr[],long long int l, long long int r,long long int toFind) {
	if (r >= l) {
		long long int mid = l + (r-l)/2;
		if (arr[mid] == toFind) {
			while(arr[mid-1] == toFind) {
				mid --;
			}
			return mid + 1;
		} else if(arr[mid] > toFind) {
			if (arr[mid-1] < toFind || mid == 0) {
				return mid + 1;
			} else {
				return binarySearch(arr,l,mid-1,toFind);
			}
		} else {
			return binarySearch(arr,mid+1,r,toFind);
		}
	}
	return -1;
}

int main() {
	long long int N,M,i,j;
	scanf("%lld %lld",&N,&M); 
	getchar();
	
	long long int arr[N+5];
	for (i = 0; i < N;i++) {
		scanf("%lld",&arr[i]);
		if(i>0){
   			if(arr[i]<arr[i-1]){
    			arr[i]=arr[i-1];
   			}
  		}
	}
	long long int ArrM,total;
	for (j = 1; j <= M;j++) {
		scanf("%lld",&ArrM);
		getchar();
		total = binarySearch(arr,0,N-1,ArrM);
		printf("%lld\n",total);
	}
	return 0;
}

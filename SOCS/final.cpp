#include <stdio.h>

long int binarySearch(long int arr1[],long int l, long int r, long int toFind){
	 if (r >= l) { 
	    long int mid = l + (r-l) / 2; 
	    
	        if (arr1[mid] == toFind) {
	            while(arr1[mid-1]== toFind){
	                mid --;
	            }    
	            return mid+1; 
	        } else if (arr1[mid] > toFind) {
	            if(arr1[mid-1] < toFind || mid==0) {
	                return mid + 1;
	            } else {
	                return binarySearch(arr1, l, mid-1, toFind);    
	            }
	        } else {
	            return binarySearch(arr1, mid + 1, r, toFind);
	        } 
	    }
	     
	    return -1; 
	}
	
int main(){
	long int N,M;
	scanf("%ld %ld",&N,&M);
	getchar();
	 
	long int arr1[N+1];
	for(long int i=0;i<N;i++){
	  scanf("%ld",&arr1[i]);
	  
	if(i>0){
   	if(arr1[i]<arr1[i-1]){
    	arr1[i]=arr1[i-1];
   	}
  	}
 	}
 
 	long int toFind,total;
 	for(long int j=1;j<=M;j++){
  	scanf("%ld",&toFind);
  	getchar();
  
  	total=binarySearch(arr1,0,N-1,toFind);
  	printf("%ld\n",total);

 	}
 	return 0;
} 

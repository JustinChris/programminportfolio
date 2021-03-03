#include <stdio.h>

long int binarysearch(long int arr1[],long int left, long int right, long int num){
 if (right >= left) { 
    long int middle = left + (right-left) / 2; 
    
        if (arr1[middle] == num) {
            while(arr1[middle-1]== num){
                middle --;
            }    
            return middle+1; 
        } else if (arr1[middle] > num) {
            if(arr1[middle-1] < num || middle==0) {
                return middle + 1;
            } else {
                return binarysearch(arr1, left, middle-1, num);    
            }
        } else {
            return binarysearch(arr1, middle + 1, right, num);
        } 
    }
     
    return -1; 
}

int main(){
 long int amount,size;
 scanf("%ld %ld",&amount,&size);
 getchar();
 
 long int arr1[amount+1];
 for(long int i=0;i<amount;i++){
  scanf("%ld",&arr1[i]);
  
  if(i>0){
   if(arr1[i]<arr1[i-1]){
    arr1[i]=arr1[i-1];
   }
  }
 }
 
 long int num,res;
 for(long int j=1;j<=size;j++){
  scanf("%ld",&num);
  getchar();
  
  res=binarysearch(arr1,0,amount-1,num);
  printf("%ld\n",res);

 }
 return 0;
} 

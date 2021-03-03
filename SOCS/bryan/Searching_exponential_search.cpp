#include <stdio.h>
 
int BinarySearch(int arr[], int low, int high, int x){
    if (low > high)
        return -1;
    int mid = (low + high)/2;
    if (x == arr[mid])
        return mid;
    else if (x < arr[mid])
        return BinarySearch(arr, low,  mid - 1, x);
    else
        return BinarySearch(arr, mid + 1,  high, x);
}


 int min(int x, int y) {
    return (x < y) ? x : y;
}

int ExponentialSearch(int arr[], int n, int x){
    int bound = 1;
    while (bound < n && arr[bound] < x)
        bound *= 2; 
    return BinarySearch(arr, bound/2, min(bound, n), x);
}

void sukasukagua (int arr[],int awal,int akhir) {
	for (int i= 0;i < akhir;i++) {
		for (int j = 0;j < akhir;j++) {
			if (arr[i] < arr[j]) {
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


int main(void){
    int arr[120];
    int d=0;
    
	FILE *in = fopen("test.txt","r");
	while(!feof(in)) {
		fscanf(in,"%d\n",&arr[d]);
		d++;
	}
    int target;
    int f = 0;
    scanf("%d", &target);
    sukasukagua(arr,0,d);
    	while (f < d) {
    	printf("%d",arr[f]);
    	f++;
    	printf(" %d",arr[f]);
    	f++;
    	printf(" %d",arr[f]);
    	f++;
    	printf("\n");
	}
    int index = ExponentialSearch(arr, d, target);
    if (index != -1){
    	printf("Element found at index %d", index);
	}else{
        printf("Element not found in the array");
	}
    return 0;
}



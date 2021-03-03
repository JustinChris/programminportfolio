#include <stdio.h>

void mergesort(int arr[],int l,int r) {
	int temp[r];
	if (l == r) return;
	int m = (l+r)/2;
	mergesort(arr,l,m);
	mergesort(arr,m+1,r);
	
	int leftArrayPointer = l;
	int rightArrayPointer = m+1;
	int idx = 0;
	
	while (leftArrayPointer <= m && rightArrayPointer <= r) {
		if (arr[leftArrayPointer] < arr[rightArrayPointer]) {
			temp[idx] = arr[leftArrayPointer];
			leftArrayPointer++;
		}else if (arr[leftArrayPointer] > arr[rightArrayPointer]) {
			temp[idx] = arr[rightArrayPointer];
			rightArrayPointer++;
		}
		idx++;
	}
	while (leftArrayPointer <= m) {
		temp[idx] = arr[leftArrayPointer];
		idx++;
		leftArrayPointer++;
	}
	while (rightArrayPointer <= r) {
		temp[idx] = arr[rightArrayPointer];
		idx++;
		rightArrayPointer++;
	}
	for (int i = l; i <= r;i++) {
		arr[i] = temp[i-l];
	}
}

int binarysearch(int start, int end, int find,int arr[]) {
	
	if (start <= end) {
		int mid = (start + end)/2;
		if (arr[mid] == find) return mid;
		else if (arr[start] == find) return start;
		else if (arr[end] == find) return end;
		else {
			if (arr[mid] > find) {
				end = mid - 1;
			}else if (arr[mid] < find) {
				start = mid +1;
			}
			return binarysearch(start,end,find,arr);
		}
	}
	else {
		return -1;
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int arr[n];
	for(int i = 0;i < n;i++) {
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,n-1);
	int t;
	scanf("%d",&t);
	int index;
	int mark;
	int flag = 0;
	for (int i= 0; i < t;i++) {
		scanf("%d",&index);
		int pilihan = binarysearch(0,n-1,index,arr);
		if (pilihan == -1) {
			printf("-1\n");
		}else {
			printf("%d\n",pilihan+1);
		}
//		for (int j = 0; j < n;j++) {
//			if (index == arr[j]) {
//				flag = 1;
//				mark = j;
//				break;
//			}
//		}
//		if (flag == 1) {
//			printf("%d\n",mark+1);
//			flag = 0;
//		}else if (flag == 0) {
//			printf("-1\n");
//		}
	}
	return 0;
}

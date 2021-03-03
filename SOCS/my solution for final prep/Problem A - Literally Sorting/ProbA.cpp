#include <stdio.h>

void merge(int Arr[], int l, int m, int r) {
	int size = r-l + 1;
	int temp[size];
	int leftIndex = l, rightIndex = m + 1;
	int tempIndex = 0;
	
	while (leftIndex <= m && rightIndex <= r) {
		if (Arr[leftIndex] <= Arr[rightIndex]) {
			temp[tempIndex] = Arr[leftIndex];
			leftIndex += 1;
		}else {
			temp[tempIndex] = Arr[rightIndex];
			rightIndex += 1;
		}
		tempIndex += 1;
	}
	
	while (leftIndex <= m) {
		temp[tempIndex] = Arr[leftIndex];
		leftIndex+=1;
		tempIndex+=1;
	}
	
	while (rightIndex <= r) {
		temp[tempIndex] = Arr[rightIndex];
		rightIndex += 1;
		tempIndex += 1;
	}
	
	for (int i = 0; i < size; i++) {
		Arr[l + i] = temp[i];
	}
	
}

void mergesort(int Arr[], int l, int r) {
	if (l == r) return;
	
	int mid = (l+r)/2;
	
	mergesort(Arr,l,mid);
	mergesort(Arr,mid+1,r);
	
	merge(Arr,l,mid,r);
}



int main() {
	int n;
	puts("Masukan Jumlah angka yang ingin di sort");
	scanf("%d",&n);
	int Arr[n];
	puts("Masukan Angka");
	for (int i = 0; i < n; i++) {
		
		scanf("%d",&Arr[i]);
	}
	mergesort(Arr,0,n-1);
	for (int i = 0; i < n; i++) {
		printf("%d ",Arr[i]);
	}
	return 0;
}

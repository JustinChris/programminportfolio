#include <stdio.h>




int merge (int urutan[], int l, int m, int r) {
	int size = r - l + 1;
	int temp[size];
	int leftIndex = l, rightIndex = m + 1;
	int tempIndex = 0;
	
	while (leftIndex <= m && rightIndex <= r) {
		if (urutan[leftIndex] <= urutan[rightIndex]) {
			temp[tempIndex] = urutan[leftIndex];
			leftIndex++;
		}else {
			temp[tempIndex] = urutan[rightIndex];
			rightIndex++;
		}
		tempIndex++;
	}
	while (leftIndex <= m) {
		temp[tempIndex] = urutan[leftIndex];
		tempIndex++;
		leftIndex++;
	}
	while (rightIndex <= r) {
		temp[tempIndex] = urutan[rightIndex];
		tempIndex++;
		rightIndex++;
	}
	for (int i = 0; i < size; i++) {
		urutan[l + i] = temp[i];
	}
}


void mergeSort(int urut[], int left, int right) {
	if (left == right) return;
	
	int mid = (left + right)/2;
	
	mergeSort(urut,left, mid);
	mergeSort(urut,mid+1, right);
	
	merge(urut, left, mid, right);
}


int main() {
	int n;
	int total = 0;
	int urutan[1000];
	scanf("%d",&n);
	int arr[1000];
	for (int i = 0; i < n; i++) {
		scanf("%d",&arr[i]);
		for (int j = 1; j <= arr[i]; j++) {
			if (arr[i] % j == 0) {
				total += j;
			}
		}
		urutan[i] = total;
		total = 0;
	}
	
	mergeSort(urutan, 0, n-1);
	
	for (int i = 0; i < n; i++) {
		printf("%d ",urutan);
	}
	
	return 0;
}

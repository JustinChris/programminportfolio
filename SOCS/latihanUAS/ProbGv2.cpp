#include <stdio.h>

struct data {
	int angka;
	int hasil;
};

void merge (struct data Array[], int l, int m, int r) {
	int size = r-l +1;
	struct data temp[size];
	int leftIndex = l, rightIndex = m + 1;
	int tempIndex = 0;
	
	while (leftIndex <= m && rightIndex <= r) {
		if (Array[leftIndex].hasil < Array[rightIndex].hasil) {
			temp[tempIndex] = Array[leftIndex];
			leftIndex++;
		}else if (Array[leftIndex].hasil > Array[rightIndex].hasil) {
			temp[tempIndex] = Array[rightIndex];
			rightIndex++;
		}else {
			if (Array[leftIndex].angka < Array[rightIndex].angka) {
				temp[tempIndex] = Array[leftIndex];
				leftIndex++;
			}else {
				temp[tempIndex] = Array[rightIndex];
				rightIndex++;
			}
		}
		tempIndex++;
	}
	
	while (leftIndex <= m) {
		temp[tempIndex] = Array[leftIndex];
		leftIndex++;
		tempIndex++;
	}
	
	while (rightIndex <= r) {
		temp[tempIndex] = Array[rightIndex];
		rightIndex++;
		tempIndex++;
	}
	
	for(int i = 0; i < size; i++) {
		Array[i + l] = temp[i];
	}
	
}

void mergeSort(struct data Array[], int left, int right) {
	if (left == right) return;
	
	int mid = (left + right)/2;
	
	mergeSort(Array, left, mid);
	mergeSort(Array, mid+1, right);
	merge(Array, left, mid, right);
}



int main() {
	struct data divisor[1005];
	int n;
	
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%d",&divisor[i].angka);
		int total = 0;
		for (int j = 1; j <= divisor[i].angka; j++) {
			if (divisor[i].angka % j == 0) {
				total += j;
			}
		}
		divisor[i].hasil = total;
	}
	mergeSort(divisor, 0, n-1);
	
	for (int i = 0; i < n; i++) {
		printf("%d",divisor[i]);
		if (i < n-1) {
			printf(" ");
		}
	}
	
	printf("\n");
	
	return 0;
}

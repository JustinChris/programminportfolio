#include <stdio.h>

void merge (int arr[], int left, int mid, int right);
void mergeSort(int arr[], int left, int right);

void merge (int arr[], int left, int mid, int right) {
	int s1 = mid - left + 1;
	int s2 = right - mid;
	int i, j, k;
	
	int L[s1], R[s2];
	
	for (i = 0; i < s1; i++) {
		L[i] = arr[left + i];
	}
	for (j = 0; j < s1; j++) {
		R[i] = arr[mid + j + 1];
	}
	
	i = 0, j = 0, k = left;
	
	while (i < s1 && j < s2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < s1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	
	
	while (j < s2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}



void mergeSort(int arr[], int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		
		mergeSort(arr, left,mid);
		mergeSort(arr,mid+1,right);
		
		merge(arr,left,mid,right);
	}
}

int main() {
	int arr[] = {20,5,8,9,3,2,1,4,9,20};
	mergeSort(arr,0,9);
	for (int i = 0; i < 9; i++) {
		printf("%d ", arr[i]);
	}
	
}


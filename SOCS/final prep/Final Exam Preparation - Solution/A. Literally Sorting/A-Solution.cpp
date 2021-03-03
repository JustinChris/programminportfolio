#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int size = right - left + 1; // combined size of both subarray
    int temp[size]; // temporary array for storing sorted elements
    int leftIndex = left, rightIndex = mid + 1; // current not taken elements of both subarray
    int tempIndex = 0; // position on temp

    while(leftIndex <= mid && rightIndex <= right) { // while there exist some elements in both subarray
        // check current element in both subarray
        if(arr[leftIndex] <= arr[rightIndex]) { // left element is smaller, so we pick that element first
            temp[tempIndex] = arr[leftIndex];
            leftIndex += 1; 
        }
        else { // otherwise, we pick the element from right subarray
            temp[tempIndex] = arr[rightIndex];
            rightIndex += 1;
        }

        tempIndex += 1; 
    }

    while(leftIndex <= mid) { // copy the remaining elements of the left subarray
        temp[tempIndex] = arr[leftIndex];
        leftIndex += 1, tempIndex += 1;
    }

    while(rightIndex <= right) { // copy the remaining elements of the right subarray
        temp[tempIndex] = arr[rightIndex];
        rightIndex += 1, tempIndex += 1;
    }

    // copy all elements from the temporary array to the original
    for(int i = 0; i < size; i++) {
        arr[left + i] = temp[i];
    }
}

void sort(int arr[], int left, int right) {
    if(left == right) return; // is already sorted (1 integer only)

    //midpoints of the array
    int mid = (left + right) / 2;

    // divide the array into two parts
    // sort each subarray individually
    sort(arr, left, mid); 
    sort(arr, mid + 1, right); 

    // merge both sorted subarray
    merge(arr, left, mid, right);
}

int main() {
	printf("test");
    int T;
    scanf("%d", &T);

    for(int tc = 0; tc < T; tc++) {
        int N; 
        scanf("%d", &N);

        int A[N];
        for(int i = 0; i < N; i++) {
            scanf("%d", &A[i]);
        }
        sort(A, 0, N - 1);

        for(int i = 0; i < N; i++) {
            if(i != 0) printf(" ");
            printf("%d", A[i]);
        }
        printf("\n");
    }

    return 0;
}

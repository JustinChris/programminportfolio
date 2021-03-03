#include <stdio.h>

// standard merge sort algorithm
void merge(int arr[], int left, int mid, int right) {
    int size = right - left + 1;
    int temp[size];
    int i = left, j = mid + 1;
    int k = 0;

    while(i <= mid && j <= right)
        temp[k++] = (arr[i] <= arr[j]) ? arr[i++] : arr[j++];

    while(i <= mid) 
        temp[k++] = arr[i++];

    while(j <= right)
        temp[k++] = arr[j++];

    for(int idx = 0; idx < size; idx++) 
        arr[left + idx] = temp[idx];
}

void sort(int arr[], int left, int right) {
    if(left == right)
        return;

    int mid = (left + right) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main() {
    int n; 
    scanf("%d", &n);

    int arr[n + 1];
    long long sum[n + 1];
    for(int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);

    sort(arr, 1, n);

    // prefix sum
    // sum[i] = arr[i] + arr[i - 1] + arr[i - 2] + ... arr[1]
    // sum[0] is obviously 0 as we don't pick any children
    sum[0] = 0;
    for(int i = 1; i <= n; i++)
        // long long to prevent overflow
        sum[i] = sum[i - 1] + (long long) arr[i];
    
    int q; 
    scanf("%d", &q);

    while(q--) {
        int num;
        scanf("%d", &num);

        // minimum number of children we can pick is 0, and the maximum is n.
        int l = 0, r = n;
        // binary search
        while(l < r) {
            int mid = (l + r + 1) / 2;
         
            // if current average is not exceeding num
            if(sum[mid] <= (long long) num * (long long) mid)
                l = mid; // try higher value
            else
                // you must find a lower value
                r = mid - 1; 
        }

        printf("%d\n", l);
    }

    return 0;
}
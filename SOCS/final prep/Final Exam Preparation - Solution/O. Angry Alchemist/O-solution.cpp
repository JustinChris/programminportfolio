#include <stdio.h>

// standard merge sort
void merge(int *a, int l, int r) {
	int temp[r - l + 1];
	int mid = (l + r) / 2;
	int i = l, j = mid + 1, k = 0;

	while(i <= mid && j <= r) temp[k++] = (a[i] <= a[j] ? a[i++] : a[j++]);
	while(i <= mid) temp[k++] = a[i++];
	while(j <= r) temp[k++] = a[j++];

	for(int i = 0; i < k; i++) {
		a[l + i] = temp[i];
	}
}

void sort(int *a, int l, int r) {
	if(l == r) return;
	int mid = (l + r) / 2;
	sort(a, l, mid);
	sort(a, mid + 1, r);
	merge(a, l, r);
}

// lowerbound binary search
// search for the lowest index where arr[index] >= x
int search(int *a, int l, int r, int x) {
	while(l < r) {
		int mid = (l + r) / 2;

		// if the current value is smaller than the target
		// we must check higher
		if(a[mid] < x) l = mid + 1; 
		else r = mid; // try checking lower index
	}
	return l;
}

int main() {
	int N, X;
	scanf("%d %d", &N, &X);

	int A[N], B[N], C[N], D[N];
	int sumAB[N * N], sumCD[N * N];

	for(int i = 0; i < N; i++) scanf("%d", &A[i]);
	for(int i = 0; i < N; i++) scanf("%d", &B[i]);
	for(int i = 0; i < N; i++) scanf("%d", &C[i]);
	for(int i = 0; i < N; i++) scanf("%d", &D[i]);

	// find all possible sum of A[i] and B[j]	
	int idx = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) { 
			sumAB[idx] = A[i] + B[j];
			idx++;
		}
	}

	// find all possible sum of C[i] and D[j]
	idx = 0;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < N; j++) {
			sumCD[idx] = C[i] + D[j];
			idx++;
		}
	}

	// sort the second array
	sort(sumCD, 0, N * N - 1);

	// ans may reach up to 1000^4 = 10^12, depending on the arrays
	long long ans = 0;

	// for every values in sumAB
	for(int i = 0; i < N * N; i++) {
		// sumAB[i] + value = X --> value = X - sumAB[i],
		// now we use this value as the target to search in binary search
		int target = X - sumAB[i]; 

		// lowerbound(target + 1) - lowerbound(target)
		// is equal to the number of elements that are equal to target in sumCD
		ans += search(sumCD, 0, N * N, target + 1) - search(sumCD, 0, N * N, target);
	}

	printf("%lld\n", ans);
}

/*
	note: if you use another method
	for example, by using addition (A + B + C + D = X)
	beware of overflows as the limit of normal long integer is around 2 x 10^9
	while the addition can reach up to 4 x 10^9
*/
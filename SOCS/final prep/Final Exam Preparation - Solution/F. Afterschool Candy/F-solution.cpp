#include <stdio.h>

struct candy {
	int price, stock;
} a[100005];

int T, N, M, K;

// standard merge sort
//sort based on the lowest price regardless of the stock
void merge(struct candy a[], int l, int r){
	int size = r - l + 1;
	struct candy temp[size];

	int mid = (l + r) / 2;
	int i = l, j = mid + 1;
	int k = 0;

	while(i <= mid && j <= r) temp[k++] = (a[i].price <= a[j].price ? a[i++] : a[j++]);
	while(i <= mid) temp[k++] = a[i++];
	while(j <= r) temp[k++] = a[j++];

	for(int i = 0; i < size; i++) {
		a[l + i] = temp[i];
	}
}

void sort(struct candy a[], int l, int r) {
	if(l == r) return;

	int mid = (l + r) / 2;
	sort(a, l, mid);
	sort(a, mid + 1, r);
	merge(a, l, r);
}

int min(int a, int b) { // find the minimum of two numbers
	return (a < b ? a : b);
}

int main() {
	scanf("%d", &T);
	for(int tc = 0; tc < T; tc++) {
		scanf("%d %d %d", &N, &M, &K);

		for(int i = 0; i < M; i++) {
			scanf("%d", &a[i].price);
		}
		for(int i = 0; i < M; i++) {
			scanf("%d", &a[i].stock);
		}
		sort(a, 0, M - 1);

		// the total number of candy you can buy
		int total = 0;
		for(int i = 0; i < M; i++) {
			// number of candy you can buy with your remaining money for the current candy
			// either you buy as much as you can, or you buy all of the stock
			int buy = min(K / a[i].price, a[i].stock); 

			K -= buy * a[i].price; // count your remaining money
			total += buy;          // add the candy to total
		}

		// if the maximum number of candy he can buy is at least N
		// then the answer is "YES", otherwise "NO"
		puts(total >= N ? "YES" : "NO");
	}
	
	return 0;
}
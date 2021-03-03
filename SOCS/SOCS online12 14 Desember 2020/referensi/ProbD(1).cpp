#include <stdio.h>
#include <string.h>
// int main -> mergesort ->  int main - binary search

void merge(int arr[], int l, int m, int r) 
{
    int temp[r - l + 1], p1 = l, p2 = m + 1, k = 0;
    while (p1 <= m && p2 <= r) 
	{
        if (arr[p1] < arr[p2]) 
		{
            temp[k++] = arr[p1++];
        }
        else {
            temp[k++] = arr[p2++];
        }
    }
    while (p1 <= m) 
	{
        temp[k++] = arr[p1++];
    }
    for (int i = 0; i < k; i++) 
	{
        arr[i + l] = temp[i];
    }
}
void mergeSort(int arr[], int l, int r) 
{
    if (l != r) 
	{
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int binarySearch(int arr[], int low, int high, int x) 
{ 
    if (high >= low) 
	{ 
        int middle = low + (high - low) / 2; 
        if (arr[middle] == x) return middle; 
        if (arr[middle] > x) return binarySearch(arr, low, middle - 1, x); 
        return binarySearch(arr, middle + 1, high, x); 
    } 
    return -1; 
}
int main()
{
	int n,query;
	int data;
	scanf("%d", &n);
	int tinggi[n+5];
	for(int i=0; i<n; i++)
	{
		scanf("%d", &tinggi[i]);
	}
	
	mergeSort(tinggi, 0 , n-1);
	
	scanf("%d", &query);
	for(int j = 0; j<query ; j++)
	{
		scanf("%d", &data);
		int x = binarySearch(tinggi , 0 , n-1 , data);
		if(x!=-1)
		{
			x =	x + 1;
		}
		printf("%d\n", x); // karena index itu mulai dari 0 maka kita kasi + 1 karena soalnya minta posisi
	}
	
	return 0;
}


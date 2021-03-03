#include <stdio.h>
#include <string.h>

void bubblesort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        // kiri -> unsorted
        // kanan -> sorted
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
			{
                int swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int i=0; i<t; i++)
	{
		int n;
		double mean=0;
		scanf("%d", &n);
		int integer[n+3];
		for(int j=0; j<n; j++)
		{
			scanf("%d", &integer[j]);
			mean = mean + integer[j]/(double)n;
		}
		bubblesort(integer , n);
		int idx,x,y; //x=index ke n/2 ----- y = index ke n/2 - 1
		double median;
		if(n%2!=0)
		{
			idx = n/2;
			// median == integer[idx]
			median = integer[idx];
		}
		else
		{
			x = n/2;
			y = (n/2)-1;
			median = (integer[x] + integer[y]) / 2.0; // 2 nya itu typecase biar int jadi float
		}
		//DEBUG
//		for(int x=0; x<n; x++)
//		{
//			printf("%d", integer[x]);
//		}
		printf("Case #%d:\n", i+1);
		printf("Mean : %.2lf\n", mean);
		printf("Median : %.2lf\n", median);
	}
	return 0;
}


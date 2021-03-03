#include <stdio.h>
#include <string.h>

//bubblesort 1 = ascending
//bubblesort 2 = descending

void bubbleSort1(long long int arr[], long long int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        // kiri -> unsorted
        // kanan -> sorted
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (arr[j] > arr[j + 1]) 
			{
                long long int swap = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = swap;
            }
        }
    }
}

void bubbleSort2(long long int arr[], long long int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        // kiri -> unsorted
        // kanan -> sorted
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (arr[j] < arr[j + 1]) 
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
	int t,collumn;
	scanf("%d", &t);
	for(int i=0; i<t; i++)
	{
		long long int sum=0;
		scanf("%d", &collumn);
		long long int arr1[collumn+5];
		long long int arr2[collumn+5];
		{
			for(int j=0; j<collumn; j++)
			{
				scanf("%lld", &arr1[j]);
			}
			
			bubbleSort1(arr1 , collumn);
			
			for(int k=0; k<collumn; k++)
			{
				scanf("%lld", &arr2[k]);
			}
			
			bubbleSort2(arr2 , collumn);
			
			for(int l = 0; l<collumn; l++)
			{
				sum += arr1[l] * arr2[l];
			}
			printf("Case #%d: %lld\n", i+1 , sum);
		}
	}
	
	return 0;
}


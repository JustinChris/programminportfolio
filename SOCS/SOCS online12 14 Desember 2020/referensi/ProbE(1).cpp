#include <stdio.h>
#include <string.h>

struct Data
{
	int number;
	int order;
	int number2;
};

void bubbleSort(struct Data angka[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        // kiri -> unsorted
        // kanan -> sorted
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (angka[j].number > angka[j + 1].number) 
			{
                struct Data swap = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = swap;
            }
        }
    }
}

void bubbleSort2(struct Data angka[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
	{
        // kiri -> unsorted
        // kanan -> sorted
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (angka[j].order > angka[j+1].order) 
			{
                struct Data swap = angka[j];
                angka[j] = angka[j + 1];
                angka[j + 1] = swap;
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
		int ctr;
		scanf("%d", &n);
		struct Data angka[n+5];
		for(int j=0; j<n; j++)
		{
			scanf("%d", &angka[j].number);
			angka[j].order = j ;
		}
		//sorting value
		bubbleSort(angka , n);
		//assign new value
		ctr = 1;
		angka[0].number2 = ctr;
		for(int k=1; k<n; k++)
		{
			if(angka[k].number==angka[k-1].number)
			{
				angka[k].number2 = ctr;
			}
			else
			{
				ctr++;
				angka[k].number2 = ctr;
			}
			
		}
		//sorting order
		bubbleSort2(angka, n);
		printf("Case #%d:", i+1);
		for(int l=0 ;l<n; l++)
		{
			printf(" %d",angka[l].number2);	
		}
		printf("\n");	
	}
	return 0;
}


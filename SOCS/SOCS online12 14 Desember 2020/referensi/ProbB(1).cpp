#include <stdio.h>
#include <string.h>

struct data
{
	char judul[1002];
	char creator[1002];
	int count;
};
//------------------------------------------------------------------------------//
void bubblesort(struct data Data[101], int n)  
{
    
	for (int i = 0; i < n - 1; i++) 
	{
        // kiri -> unsorted
        // kanan -> sorted
        for (int j = 0; j < n - i - 1; j++) 
		{
            if (Data[j].count < Data[j + 1].count) 
			{
                struct data swap = Data[j];
                Data[j] = Data[j + 1];
                Data[j + 1] = swap;
            }
            if(Data[j].count == Data[j+1].count)
            {
            	if(strcmp(Data[j].judul,Data[j+1].judul)>0)
            	{
            		struct data swap = Data[j];
                	Data[j] = Data[j + 1];
               		Data[j + 1] = swap;
				}
			}
        }
    }
}
//------------------------------------------------------------------------------//

int main()
{
	FILE *file;
	file = fopen("testdata.in", "r");
	struct data Data[101];
	int i = 0;
	while(!feof(file))
	{
		fscanf(file , "%[^#]#%[^#]#%d\n", Data[i].judul , Data[i].creator, &Data[i].count);
		i++;
	}
	//printf("n : %d", i);
	bubblesort(Data , i);
	for(int j = 0; j<i; j++)
	{
		printf("%s by %s - %d\n",Data[j].judul , Data[j].creator , Data[j].count);
	}
	fclose(file);
	return 0;
}
//------------------------------------------------------------------------------//


#include <stdio.h>
#include <string.h>

int main()
{
	FILE *data;
	int n,output;
	char acronym[105][105];
	char fullname[105][105];
	data = fopen("testdata.txt","r");
	fscanf(data, "%d\n", &n);
	for(int i=0; i<n; i++)
	{
		fscanf(data, "%[^#]#%s\n", acronym[i], fullname[i]);
		int length = strlen(acronym[i]);
		acronym[i][length]='\0'; //null terminator dibutuhkan agar string yang dicek[acronym] tidak berlanjur ke index berikutnya
		int length2 = strlen(fullname[i]);
		fullname[i][length2]='\0';	
		//printf("%s %s\n", acronym[i], fullname[i]);
	}
	fscanf(data, "%d", &output);
	char substitute[105];
	for (int j=0; j<output; j++)
	{
		printf("Case #%d:\n", j+1);
		char x='\0'; //null terminator
		while(x!='\n')
		{
			fscanf(data, "%s%c", substitute , &x);
			for(int k=0; k<n; k++)
			{
				if(strcmp(substitute, acronym[k])==0)
				{
					//printf("asas\n");
					strcpy(substitute, fullname[k]);
				//	break;
				}
			}
			printf("%s%c", substitute , x);
		}
	}
	return 0;
}

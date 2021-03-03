#include <stdio.h>

int main() {
	int d=0;
	int arr[120];
	FILE *in = fopen("Number.txt","r");
	while(!feof(in)) {
		fscanf(in,"%d\n",&arr[d]);
		d++;
	}
	int tar;
	scanf("%d",&tar);
	//linear search
	for (int i =0; i < d;i++) {
		if (arr[i] == tar) {
			printf("at index = %d",i);
			break;
		}
	}
	
	return 0;
}

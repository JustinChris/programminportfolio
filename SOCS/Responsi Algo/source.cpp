#include <string.h>
#include <stdio.h>

struct data {
	char nim[12];
	char name[25];
	int age;
	float GPA;
};
struct data mahasiswa[100000];

void merge (int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	
	struct data L[n1], R[n2];
	
	for (i = 0; i < n1; i++)
		L[i] = mahasiswa[l + i];
	for (j = 0; j < n2; j++)
		R[j] = mahasiswa[m+1+j];
		
	i = 0;
	j = 0;
	k = l;
	
	while (i < n1 && j < n2) {
		if (strcmp(L[i].nim,R[j].nim) <= 0) {
			mahasiswa[k] = L[i];
			i++;
		}
		else {
			mahasiswa[k] = R[j];
			j++;
		}
		k++;
	}
	
	while (i < n1) {
		mahasiswa[k] = L[i];
		i++;
		k++;
	}
	
	
	while (j < n2) {
		mahasiswa[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int l, int r) {
	if (l < r) {
		int m = l + (r-l) / 2;
		
		mergeSort(l,m);
		mergeSort(m+1,r);
		merge(l,m,r);
	}
}

int main() {
	FILE *in = fopen("testdata.in","r");
	int i = 0;
	int total;
	int testcase;
	fscanf(in,"%d",&total);
	while (!feof(in)) {
		fscanf(in,"%[^;];%[^;];%d;%f\n",&mahasiswa[i].nim,&mahasiswa[i].name,&mahasiswa[i].age,&mahasiswa[i].GPA);
		i++;
	}
	fscanf(in,"%d",&testcase);
	binarySearch()
	return 0;
}

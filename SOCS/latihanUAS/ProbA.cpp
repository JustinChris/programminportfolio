#include <string.h>
#include <stdio.h>

struct data2 {
	char namaID[30];
	char asal[105];
	char tujuan[105];
};

struct data1 {
	char Id[30];
	char Time[6];
};
struct data1 schedule[1005];
struct data2 goal[1005];

int main() {
	int n;
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		scanf("%s %s",schedule[i].Id,schedule[i].Time);
	}
	for (int i = 0; i < n; i++) {
		scanf("%s %s %s", goal[i].namaID,goal[i].asal,goal[i].tujuan);
	}
	
	for (int i = 0; i < n; i++) {
		printf("%s %s",schedule[i].Id, schedule[i].Time);
		for (int j = 0; j < n;j++) {
			if (strcmp(schedule[i].Id,goal[j].namaID) == 0){
				printf(" %s %s",goal[j].asal,goal[j].tujuan);
				break;
			}
		}
		printf("\n");
	}
	
	
	return 0;
}

#include <stdio.h>
#include <string.h>

struct data{
	char nama[25];
	char profesi[25];
	char gen[25];
	int active;
};

struct data table[101];

int unik(char name[]){
 	for(int i = 1; i<101; i++){
  		if(strcmp(name, table[i].nama) == 0){
   		return 1;
  		}
 	}
 	return 0;
}
void add(char name[], char gender[], char position[]) {
 	for(int i = 1; i<101; i++){
  		if(table[i].active == 0){
			strcpy(table[i].nama, name);
			strcpy(table[i].gen, gender);
			strcpy(table[i].profesi, position);
			table[i].active = 1;
			return;
	  	}
	}
}
void swap(int x, int y){
	struct data temp;
	temp.active = table[x].active;
	strcpy(temp.nama, table[x].nama);
	
	table[x].active = table[y].active;
	strcpy(table[x].nama, table[y].nama);
	
	table[y].active = temp.active;
	strcpy(table[y].nama, temp.nama);

}

void retire(int x){
	table[x].active = 2;
}

int main(){
	int N;
	scanf("%d", &N);
	getchar();
	for(int i = 1; i<=N; i++){
	    int input; char name[25]; char position[25]; char gender[25]; int index1; int index2;
	    scanf("%d", &input);getchar();
		if (input == 1) {
	    	scanf("%[^\n]s", name); getchar();
	    	scanf("%[^\n]s", gender); getchar();
	    	scanf("%[^\n]s", position); getchar();
	    	if(unik(name) != 1){
	        	add(name, gender, position);
	        }
	        
	   	}else if (input == 2) {
	    	scanf("%d %d", &index1, &index2); getchar();
		    if(table[index1].active != 1 || table[index2].active != 1) { }
			else {
		     	swap(index1, index2);
		   	}
		}else if (input == 3) {
		    	scanf("%d", &index1); getchar();
		    	table[index1].active = 0;
		}else if (input == 4) {
		    	scanf("%d", &index1); getchar();
		    	retire(index1);
		}
	}
	for(int i = 1; i<101; i++){
		if(table[i].active == 1){
      	printf("%s\n", table[i].nama);
  		}
 	}
}

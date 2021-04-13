#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define SIZE 256

struct Monster{
	char ID[12];
	char Name[25];
	char Type[12];
	double Size;
	char Loc1[30];
	char Loc2[30];
	Monster *next, *prev;
}*head[SIZE], *tail[SIZE], *temp;

void printMenu(){
	puts("==========================");
	puts("<< Monster Encyclopedia >>");
	puts("==========================");
	puts("1. Insert New Monster");
	puts("2. Change Monster Data");
	puts("3. Remove Monster");
	puts("4. Close Book");
	printf("Choose: ");
}

void printList(){
	int countTotalOrder = 0;
	for (int i = 0; i < SIZE; i++) {
		if (head[i] == NULL) {
			countTotalOrder++;
		}else {
			temp = head[i];
			while(temp != NULL) {
				printf("=============================\n");
				printf("Id      	: %s\n",temp->ID);
				printf("Name    	: %s\n",temp->Name);
				printf("Type    	: %s\n",temp->Type);
				printf("Size    	: %.2lf\n",temp->Size);
				printf("Location    : %s %s\n",temp->Loc1, temp->Loc2);
				printf("=============================\n");
				temp = temp->next;
			}
			puts("");
		}
	}
	if (countTotalOrder == SIZE) {
		printf("There is no Monster in the book\n");
	}
}

int getHash(char *ID) {
	int sum = 0;
	for (int i = 0; i < strlen(ID); i++){
		sum += ID[i];
	}
	return sum % SIZE;
}

Monster *newMonster(char *ID, char *Name, char *Type, double size, char *Loc1 , char *Loc2){
	Monster *monster = (Monster *)malloc(sizeof(Monster));
	strcpy(monster->ID, ID);
	strcpy(monster->Name,Name);
	strcpy(monster->Type,Type);
	monster->Size = size;
	strcpy(monster->Loc1, Loc1);
	strcpy(monster->Loc2, Loc2);
	monster->prev = monster->next = NULL;
}

void addMonster (char *ID, char *Name, char *Type, double size, char *Loc1 , char *Loc2){
	Monster *monster = newMonster(ID,Name,Type,size,Loc1,Loc2);
	int idx = getHash(ID);
	
	if (head[idx] == NULL) {
		head[idx] = tail[idx] = monster;
	}else if (strcmp(head[idx]->ID,ID) > 0){
		head[idx]->prev = monster;
		monster->next = head[idx];
		head[idx] = monster;
	}else if (strcmp(tail[idx]->ID,ID) < 0){
		tail[idx]->next = monster;
		monster->prev = tail[idx];
		tail[idx] = monster;
	}else {
		temp = head[idx];
		
		while(strcmp(temp->ID,ID) < 0){
			temp = temp->next;
		}
		
		temp->next->prev = monster;
		monster->prev = temp;
		monster->next = temp->next;
		temp->next = monster;
		
	}
}

void InsertMonster() {
	char addID[12]={'\0'};
	char addname[25];
	char addtype[12];
	double addsize;
	char addLoc1[30];
	char addLoc2[30];
	
	do {
		printf("Input monster name [3 - 20 characters & Startswith Capital Letter]: ");
		scanf("%[^\n]",addname);
		getchar();
	} while (strlen(addname) < 3 || strlen(addname) > 20 || addname[0] < 65 || addname[0] > 90);
	
	do {
		printf("Input monster type [Large | Small | Endemic | Pets] (case sensitive): ");
		scanf("%[^\n]",addtype);
		getchar();
	} while (strcmp(addtype,"Large") != 0 && strcmp(addtype,"Small") != 0 && strcmp(addtype,"Endemic") != 0 && strcmp(addtype,"Pets") != 0);
	
	do {
		printf("Input monster size [100.0 - 5000.0]: ");
		scanf("%lf",&addsize);
		getchar();
	} while (addsize < 100.0 || addsize > 5000.0);
	
	do {
		printf("Input monster location [endswith ' Biome'] (case sensitive): ");
		scanf("%s %s",addLoc1,addLoc2);
		getchar();
	} while (strcmp(addLoc2,"Biome") != 0);
	
	// Make The ID
	srand(time(0));
	int id = rand() % 1000;
	char strID[12];
	sprintf(strID, "%d", id);
	addID[0] = addname[0]; 
	for (int i = 0; i < 3;i++) {
		if (addname[i] < 65 || addname[i] > 90){
			addID[i] = addname[i] - 32;
		}else{
			addID[i] = addname[i];
		}
	}
	strcat(addID,strID);
	
	addMonster(addID,addname,addtype,addsize,addLoc1,addLoc2);
	
	printf("New monster successfully added!\n");
	printf("Press enter to continue...");
	getchar();
	
}

void SearchMonster(){
	system("cls");
	char changename[25];
	char changetype[12];
	double changesize;
	char changeLoc1[30];
	char changeLoc2[30];
	char changeID[12];
	
	printList();
	
	printf("Input monster id to update: ");
	scanf("%[^\n]",changeID);
	getchar();
	int idx = getHash(changeID);
	
	if (head[idx]->ID == NULL){
		printf("Monster not found");
		printf("Press enter to continue...");
		getchar();
		getchar();
		return;
	} else if (strcmp(head[idx]->ID, changeID) == 0){
		temp = head[idx];
	} else if (strcmp(tail[idx]->ID, changeID) == 0){
		temp = tail[idx];
	} else {
		temp = head[idx];
		
		while (strcmp(temp->ID,changeID) != 0 && temp != NULL) {
			temp = temp->next;
		}
	}
	if (temp == NULL) {
		printf("Monster not found");
		printf("Press enter to continue...");
		getchar();
		return;
	}
	
	printf("[Input 0 to skip update]\n");
	do {
		printf("Input monster name [3 - 20 characters & Startswith Capital Letter]: ");
		scanf("%[^\n]",changename);
		getchar();
		if (strcmp(changename,"0") == 0){
			break;
		}
	} while (strlen(changename) < 3 || strlen(changename) > 20 || changename[0] < 65 || changename[0] > 90);
	
	do {
		printf("Input monster type [Large | Small | Endemic | Pets] (case sensitive): ");
		scanf("%[^\n]",changetype);
		getchar();
		if (strcmp(changetype,"0") == 0) break;
	} while (strcmp(changetype,"Large") != 0 && strcmp(changetype,"Small") != 0 && strcmp(changetype,"Endemic") != 0 && strcmp(changetype,"Pets") != 0);
			
	do {
		printf("Input monster size [100.0 - 5000.0]: ");
		scanf("%lf",&changesize);
		getchar();
		if (changesize == 0) break;
	} while (changesize < 100.0 || changesize > 5000.0);
			
	do {
		printf("Input monster location [endswith ' Biome'] (case sensitive): ");
		scanf("%s %s",changeLoc1,changeLoc2);
		getchar();
		if (strcmp(changeLoc1,"0") == 0) break;
	} while (strcmp(changeLoc2,"Biome") != 0);
			
	if (strcmp(changename,"0") != 0) {
		strcpy(temp->Name,changename);
	}
	if (strcmp(changetype,"0") != 0){
		strcpy(temp->Type,changetype);
	}
	if (changesize != 0){
		temp->Size = changesize;
	}
	if (strcmp(changeLoc1,"0") != 0){
		strcpy(temp->Loc1,changeLoc1);
		strcpy(temp->Loc2,changeLoc2);
	}
	printf("Monster successfully updated!\n");
	printf("Press enter to continue");
	getchar();
}

void DeleteMonster(){
	system("cls");
	char deleteID[12];
	printList();
	printf("Input monster id to Delete: ");
	scanf("%[^\n]",deleteID);
	getchar();
	int idx = getHash(deleteID);
	
	if (head[idx]->ID == NULL){
		printf("Monster not found");
		printf("Press enter to continue...");
		getchar();
		return;
	} else if (strcmp(head[idx]->ID, deleteID) == 0){
		if (head[idx] == tail[idx]) {
			system("cls");
			temp = head[idx];
			printf("=============================\n");
			printf("Id      	: %s\n",temp->ID);
			printf("Name    	: %s\n",temp->Name);
			printf("Type    	: %s\n",temp->Type);
			printf("Size    	: %.2lf\n",temp->Size);
			printf("Location    : %s %s\n",temp->Loc1, temp->Loc2);
			printf("=============================\n");
			printf("Monster successfully deleted!\n");
			printf("Press enter to continue...");
			getchar();
			free(head[idx]);
			head[idx] = tail[idx] = NULL;
		}else {
			system("cls");
			temp = head[idx];
			printf("=============================\n");
			printf("Id      	: %s\n",temp->ID);
			printf("Name    	: %s\n",temp->Name);
			printf("Type    	: %s\n",temp->Type);
			printf("Size    	: %.2lf\n",temp->Size);
			printf("Location    : %s %s\n",temp->Loc1, temp->Loc2);
			printf("=============================\n");
			printf("Monster successfully deleted!\n");
			printf("Press enter to continue...");
			getchar();
			head[idx] = temp->next;
			head[idx]->prev = NULL;
			free(temp);
		}
	} else if (strcmp(tail[idx]->ID, deleteID) == 0){
		if (head[idx] == tail[idx]) {
			system("cls");
			temp = tail[idx];
			printf("=============================\n");
			printf("Id      	: %s\n",temp->ID);
			printf("Name    	: %s\n",temp->Name);
			printf("Type    	: %s\n",temp->Type);
			printf("Size    	: %.2lf\n",temp->Size);
			printf("Location    : %s %s\n",temp->Loc1, temp->Loc2);
			printf("=============================\n");
			printf("Monster successfully deleted!\n");
			printf("Press enter to continue...");
			getchar();
			free(head[idx]);
			head[idx] = tail[idx] = NULL;
		}else {
			system("cls");
			temp = tail[idx];
			printf("=============================\n");
			printf("Id      	: %s\n",temp->ID);
			printf("Name    	: %s\n",temp->Name);
			printf("Type    	: %s\n",temp->Type);
			printf("Size    	: %.2lf\n",temp->Size);
			printf("Location    : %s %s\n",temp->Loc1, temp->Loc2);
			printf("=============================\n");
			printf("Monster successfully deleted!\n");
			printf("Press enter to continue...");
			getchar();
			tail[idx] = temp->prev;
			tail[idx]->next = NULL;
			free(temp);
		}
	} else {
		temp = head[idx];
		
		while (strcmp(temp->ID,deleteID) != 0 && temp != NULL) {
			temp = temp->next;
		}
		system("cls");
		printf("=============================\n");
		printf("Id      	: %s\n",temp->ID);
		printf("Name    	: %s\n",temp->Name);
		printf("Type    	: %s\n",temp->Type);
		printf("Size    	: %.2lf\n",temp->Size);
		printf("Location    : %s %s\n",temp->Loc1, temp->Loc2);
		printf("=============================\n");
		printf("Monster successfully deleted!\n");
		printf("Press enter to continue...");
		getchar();
		temp->next->prev = temp->prev;
		temp->prev->next = temp->next;
		free(temp);
	}
	
}


int main() {
	bool askAgain = true;
	int menuChoose;
	
	while(askAgain){
		system("cls");
		printList();
		printMenu();
		scanf("%d",&menuChoose); getchar();
		switch(menuChoose){
			case 1: InsertMonster(); break;
			case 2: SearchMonster(); break;
			case 3: DeleteMonster(); break;
			case 4: printf("Thank you for using monster book!\n"); askAgain = false; break;
		}
	}
	
	return 0;
}

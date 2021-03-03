#include<stdio.h>
#include<string.h>

struct cnd{ //information of the candidates
	char name[15];
	int totalVotes = 0;
	int cityWon = 0;
};

//sorting using bubble sort
void swap(struct cnd *i, struct cnd *j){
	struct cnd temp = *i;
	*i = *j;
	*j = temp;
}
int mustSwap(struct cnd i, struct cnd j){
	if(i.totalVotes == j.totalVotes){
		//it the total votes the same
		//swap if i has lower cities won
		return i.cityWon < j.cityWon;
	}
	//swap if i's total votes lower than j
	return i.totalVotes < j.totalVotes;
}
void sort(struct cnd dt[],int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(mustSwap(dt[i],dt[j]))
				swap(&dt[i],&dt[j]);
		}
	}
	return;
}

int main(){

	int n;
	scanf("%d%*c",&n);
	struct cnd person[n];
	for(int i=0;i<n;i++)
		scanf("%s%*c",person[i].name);

	int c;
	scanf("%d%*c",&c);
	while(c--){
		char cityName[15]; int q;
		scanf("%s %d%*c",cityName,&q);
		char winner[n][15]; //this will be used for listing the city winner
		memset(winner,0,sizeof(winner)); //set all to null value

		int maxVote = -1, jumMax = 0;
		while(q--){
			char tempName[15]; int vote;
			scanf("%s %d%*c",tempName, &vote);
			for(int i=0;i<n;i++){
				//note the votes for candidates
				if(strcmp(tempName, person[i].name) == 0){
					person[i].totalVotes += vote;
					break;
				}
			}
			if(vote > maxVote){
				//reset back to normal since there are larger votes 
				//than before votes
				maxVote = vote;
				jumMax = 0;
				strcpy(winner[jumMax++], tempName);
			}
			else if(vote == maxVote){
				//more than 1 candidates win in the city
				strcpy(winner[jumMax++], tempName);
			}
		}
		//list the winner of the city
		for(int i=0;i<jumMax;i++){
			for(int j=0;j<n;j++){
				if(strcmp(winner[i], person[j].name) == 0){
					person[j].cityWon += 1;
					break;
				}
			}
		}
	}

	//sort the candidates based on the voting result
	sort(person,n);

	//if person[0] stats (total votes and cities won) same with person[1] it means that
	//there are more than 1 winner so the election must be repeated
	//else the person[0] is the winer
	if(person[0].totalVotes == person[1].totalVotes && person[0].cityWon == person[1].cityWon)
		printf("Election must be repeated\n");
	else	printf("%s wins the election\n", person[0].name);
}
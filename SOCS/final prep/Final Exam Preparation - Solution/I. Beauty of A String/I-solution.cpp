#include<stdio.h>
int abs(int x){
	if(x < 0)	return -1*x;
	return x;
}

char s[15];
//listed value obtained
int value[405] = {0};

//To keep the permutated string
char temp[15];
int taken[15] = {0};

//General Permutation Code
void perm(int x, int n){
	if(x == n){
		//Getting the beauty values of the string
		int sum = 0;
		for(int i=1;i<n;i++)
			sum += abs(temp[i]-temp[i-1]);
		//Mark the value obtained
		value[sum] = 1;
		return;
	}
	for(int i=0;i<n;i++){
		if(taken[i] == 0){
			taken[i] = 1;
			temp[x] = s[i];
			perm(x+1, n);
			taken[i] = 0;
		}
	}
	return;
}

int main(){
	int n;
	scanf("%d%*c",&n);
	scanf("%[^\n]%*c",s);
	perm(0,n);
	int ans = 0;
	//getting numbers of distinct values obtained
	for(int i=0;i<=400;i++)
		ans += value[i];
	printf("%d\n",ans);
	return 0;
}
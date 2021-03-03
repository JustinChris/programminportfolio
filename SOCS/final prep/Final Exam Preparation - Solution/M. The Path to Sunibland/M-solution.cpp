#include<stdio.h>
#include<string.h>
//All 4 possible movement
const int d4i[4] = {-1, 0, 1, 0};
const int d4j[4] = {0, 1, 0, -1};
//The printed path
const char dir[4] = {'U','R','D','L'};

const int MAXN = 6;
char petak[MAXN][MAXN];
int pass[MAXN][MAXN];

//String sorting using merge and sort
int cmp(char x[], char y[]){
	int lenX = strlen(x), lenY = strlen(y);
	if(lenX == lenY){
        //if both lengths are same, then compared ascending
		return strcmp(x,y) < 0;
    }
    //Comparing the string in ascending
	return lenX < lenY;
}
void merge(char arr[][50], int aL, int aR, int bL, int bR){
	char temp[bR - aL + 1][50];
	int idxA = aL, idxB = bL, idxT = 0;
	while(idxA <= aR && idxB <= bR){
		if(cmp(arr[idxA],arr[idxB])){
			strcpy(temp[idxT], arr[idxA]);
            idxA++;
        }
		else{
            strcpy(temp[idxT], arr[idxB]);
            idxB++;
        }
        idxT++;
    }
	while(idxA <= aR){
		strcpy(temp[idxT], arr[idxA]);
        idxA++;
    }
	while(idxB <= bR){
        strcpy(temp[idxT], arr[idxB]);
        idxB++;
    }
	for(int i=0;i<idxT;i++){
		strcpy(arr[i+aL], temp[i]);
    }
}
void mergeSort(char arr[][50],int l,int r){
	if(l >= r)
		return;
	int mid = (l+r)/2;
	mergeSort(arr,l,mid);
	mergeSort(arr,mid+1,r);
	merge(arr,l,mid,mid+1,r);
}

struct loc{
    int i,j;
};
//If the position still in range
bool valid(int i,int j,int n,int m){
    return (i >= 0 && i < n && j >= 0 && j < m);
}

// how many possibilities
int jum = 0;
//list of the possibilities
char ans[1000000][50];
void go(struct loc curr,int n,int m,char order[]){
    if(petak[curr.i][curr.j] == 'E'){
        strcpy(ans[jum++], order);
        return;
    }
    for(int k=0;k<4;k++){
        struct loc pos = {curr.i+d4i[k], curr.j+d4j[k]};
        //Check if it's still in the border
        if(!(valid(pos.i,pos.j,n,m)))
            continue;
        //Check if that area hasn't been passed yet and walkable
        if(pass[pos.i][pos.j] == 0 && petak[pos.i][pos.j] != '#'){
            pass[pos.i][pos.j] = 1;
            //making a temporary string since we don't want to change the order string
            char temp[55];
            strcpy(temp,order);
            //applying strncat to append the path to the current order
            go(pos, n, m, strncat(temp, &dir[k], 1));
            pass[pos.i][pos.j] = 0;
        }
    }
    return;
}

int main(){
	int n,m;
    scanf("%d %d%*c",&n,&m);
    memset(pass,0,sizeof(pass));
    struct loc start;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%c",&petak[i][j]);
            //finding the start position
            if(petak[i][j]=='S')
                start = {i,j};
        }
        getchar();
    }


    petak[start.i][start.j] = 1;

    char temp[50] = {0};
    go(start, n, m,temp);

    //sort the answer
    mergeSort(ans,0,jum-1);

	printf("%d\n",jum);
	for(int i=0;i<jum;i++)
		printf("%s\n",ans[i]);
}
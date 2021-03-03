#include <stdio.h>
int n,arr[7];
int count;
bool visited[8];
void permutation(int len){
    if(len==n){
        for(int i=0;i<n;++i) {
        printf("%d",arr[i]);	
		}
        printf("\n");
        return;
    }
    for(int i=1;i<=n;++i){
    	printf("\n%d ini adalah i\n",i);
        if(!visited[i]){
            visited[i]=true;
			printf("\nlewat %d dan %d serta %d\n",count,len,i);
			if(visited[i]){
				printf("TRUE\n");
			}else {
				printf("FALSE\n");
			}
            arr[len]=i;
            count++;
            permutation(len+1);
            visited[i]=false;
        }
    }
    
    return;
}
int main(){
	int T;
    scanf("%d",&T);
    for(int i=0;i<T;++i){
        scanf("%d",&n);
        printf("Case #%d:\n",i+1);
        permutation(0);
    }
}


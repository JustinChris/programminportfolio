#include <stdio.h>
//Fail == don't like each other
int n, m, k;
int ans[10];
//List of fail pair
int fail[10][10];

//Combinatorics Generate
void generate(int index, int depth) {
    if(depth == k) {
        //Check whether there're fail pairs or not
        for(int i = 0; i < k; i++) {
            for(int j = 0; j < k; j++) {
                if(fail[ans[i]][ans[j]]) return;
            }
        }
        //Print the possible combination
        for(int i = 0; i < k; i++) {
            if(i != 0) printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
        return;
    }

    for(int i = index + 1; i <= n; i++) {
        ans[depth] = i;
        generate(i, depth + 1);
    } 
}

int main() {
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        //Mark the fail pairs
        fail[a][b] = 1;
        fail[b][a] = 1;
    }

    generate(0, 0);
    return 0;
}
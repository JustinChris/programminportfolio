#include <stdio.h>
#include <string.h>

struct person { 
    int number;
    int color;
    char name[51];
};

char colorList[][10] = {
	// values:
	// 0      1        2         3        4       5         6
    "Red", "Orange", "Yellow", "Green", "Blue", "Indigo", "Violet"
    
    // smaller value indicates higher priority
};

int needSwap(struct person a, struct person b) {
	if(a.number == b.number) {
		// if the number if same
		// then swap only if a has a lower color priority
		return a.color > b.color;
	}
	else {
		// else check if a's number is smaller
		return a.number < b.number;
	}
}

void swap(struct person *a, struct person *b) {
    struct person temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K); 
    
    struct person A[N];
    for(int i = 0; i < N; i++) {
        char input[10]; // temporary string, for storing the color input
        scanf("\n%[^#]#%d#%[^\n]", A[i].name, &A[i].number, input);
    
    	// assign the correct value to the participant's color
    	// easier than to compare the color one by one
        for(int j = 0; j < 7; j++) {
            if(strcmp(input, colorList[j]) == 0) {
                A[i].color = j;
            }
        }
    }
	
	// sorting
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
        	if(needSwap(A[i], A[j])) swap(&A[i], &A[j]); 
        }
    }
	
	// since the array is sorted, simply check the first K people
    int jojo = 0, lili = 0;
    for(int i = 0; i < K; i++) {
		// check whether jojo and lili exist within those K people
        if(strcmp(A[i].name, "jojo") == 0) jojo = 1;
        if(strcmp(A[i].name, "lili") == 0) lili = 1;
    }
	
	// if both jojo and lili exist, print "YES"
	// otherwise, "NO"
    puts((jojo && lili) ? "YES" : "NO");
}
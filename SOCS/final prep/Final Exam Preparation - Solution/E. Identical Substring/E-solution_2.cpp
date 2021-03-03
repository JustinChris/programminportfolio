#include <stdio.h>
#include <string.h>

int main() {
	char S[1005];
	int N;

	scanf("%s", S);
	scanf("%d", &N);

	int len = strlen(S); 

	for(int i = 0; i <= len - N; i++) {
		int valid = 1; // assume that the current substring is valid

		// check each character in the substring, compare with the first character
		for(int j = 1; j < N; j++) {
			if(S[i + j] != S[i]) valid = 0;
		}

		// if the current substring is valid, then print the answer
		if(valid) {
			printf("%d %d\n", i + 1, i + N);
			return 0;
		}
	}

	// if there is no answer, print -1
	printf("-1\n");
	return 0;
}
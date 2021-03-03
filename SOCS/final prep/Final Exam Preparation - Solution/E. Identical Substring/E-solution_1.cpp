#include <stdio.h>

int main() {
	char S[1005];
	int N;

	scanf("%s", S);
	scanf("%d", &N);

	int count = 1; // consecutive identical character counter
	for(int i = 0; S[i] != '\0'; i++) {
		// if the current character is identical to the previous character
		// add the counter by 1
		if(i != 0 && S[i] == S[i - 1]) count++;
		else count = 1; // else reset back to 1

		// if counter has reached the target
		// the substring fulfills the condition
		if(count == N) {
			// print the answer
			printf("%d %d\n", i - N + 2, i + 1);
			return 0; // finish the program.
		}
	}
	
	// if there is no answer, print -1
	printf("-1\n");
	return 0;
}
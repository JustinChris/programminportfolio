#include <stdio.h>
#include <string.h>

int main() {
    int k; scanf("%d", &k);

    int change[256] = {0}; 
    // by default, the value is all 0
	// saving ascii value
	
    while(k--) {
        char input[4];
        scanf("%s", input);
        
        change[input[0]] = input[2]; // uppercase
        change[input[0] + 32] = input[2] + 32; // lowercase
    }

    scanf("%*d");
    char string[1005];
    scanf("%*c%[^\n]", string);

    char *word;
    int first = 1;

    word = strtok(string, " "); // split the string into words
    while(word != NULL) {
        int exist = 0;
        
        // for every character in word
        for(int i = 0; word[i] != '\0'; i++) {
            if(change[word[i]]) { // if the character can be translated
                exist = 1; // we will print this word
                word[i] = change[word[i]]; // decrypt the character
            }
        }

        if(exist) {
            if(first) { // is it the first word printed? no need for space
                printf("%s", word);
                first = 0;
            }
            else { // always print space before the word
                printf(" %s", word);
            }    
        }

        word = strtok(NULL, " ");
    }
    printf("\n");
}
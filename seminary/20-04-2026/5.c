#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char word[100];
    printf("Enter the word: ");
    scanf("%99s", &word);

    int length = strlen(word);
    int attempts = 0;
    int n_guessed = 0;
    char* guessed = (char*)calloc(length, sizeof(char));
    
    while (n_guessed < length && attempts < length + 2)
    {
        for (int i = 0; i < length; i++) {
            if (guessed[i] == 1) {
                printf("%c", word[i]);
            }
            else {
                printf("_");
            }
        }
        printf("\n");

        char letter;
        printf("Guess #%d: ", attempts + 1);
        scanf(" %c", &letter);
        attempts++;

        for (int i = 0; i < length; i++) {
            if (guessed[i] == 1) {
                continue;
            }

            if (word[i] == letter) {
                n_guessed += 1;
                guessed[i] = 1;
            }            
        }
    }

    if (n_guessed == length) {
        printf("You win!");
    }
    else {
        printf("You lost!");
    }

    return 0;
}
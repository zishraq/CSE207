#include <stdio.h>

int main() {
    char text[100];
    int vowels, consonants;

    printf("Input a string: ");
    fgets(text, 100, stdin);

    for (int i = 0; *(text + i) != '\n'; i++) {
        if (*(text + i) == 'a' || *(text + i) == 'e' || *(text + i) == 'i' || *(text + i) == 'o' || *(text + i) == 'u') {
            vowels++;
        } else {
            consonants++;
        }
    }

    printf("Number of vowels: %d\n", vowels);
    printf("Number of consonants: %d\n", consonants);

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

int main() {
    char input[500];
    char *words[MAX_WORDS];
    int count = 0;

    if (scanf("%[^\n]", input) != 1) {
        return 0;
    }

    char *token = strtok(input, " ");
    while (token != NULL && count < MAX_WORDS) {
        words[count] = strdup(token);
        count++;
        token = strtok(NULL, " ");
    }

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            int len1 = strlen(words[j]);
            int len2 = strlen(words[j + 1]);
            int shouldSwap = 0;

            if (len1 > len2) {
                shouldSwap = 1;
            } else if (len1 == len2) {
                if (strcmp(words[j], words[j + 1]) > 0) {
                    shouldSwap = 1;
                }
            }

            if (shouldSwap) {
                char *temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    return 0;
}

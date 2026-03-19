#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_WORDS 100
#define MAX_LEN 50

int compare(const void *a, const void *b) {
    char *word1 = *(char **)a;
    char *word2 = *(char **)b;
    int len1 = strlen(word1), len2 = strlen(word2);
    
    if (len1 != len2) {
        return len2 - len1;
    }
    return strcmp(word1, word2);
}

int main() {
    char input[500];
    char *words[MAX_WORDS];
    int count = 0;

    scanf("%[^\n]", input);

    char *token = strtok(input, " \n");
    while (token != NULL && count < MAX_WORDS) {
        words[count] = strdup(token);
        count++;
        token = strtok(NULL, " \n");
    }

    qsort(words, count, sizeof(char *), compare);

    for (int i = 0; i < count; i++) {
        printf("%s\n", words[i]);
        free(words[i]);
    }

    return 0;
}

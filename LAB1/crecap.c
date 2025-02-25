#include <stdio.h>
#include <stdlib.h>

int convert(const char *str) {
    int r = 0;
    while (*str >= '0' && *str <= '9') {
        r = r * 10 + (*str - '0');
        str++;
    }
    return r;
}

int main() {
    FILE *file = fopen("in.txt", "r");
    if (file == NULL) {
        printf("error\n");
        return 1;
    }

    char line[100];
    int sum = 0;
    while (fgets(line, sizeof(line), file)) {
        sum += convert(line);
    }

    fclose(file);
    printf("%d\n", sum);
    return 0;
}

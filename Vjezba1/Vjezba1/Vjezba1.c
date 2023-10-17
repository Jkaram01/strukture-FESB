#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int count = 0;
    char ch;
    FILE* file = fopen("studenti.txt", "r");

    if (file == NULL) {
        printf("ERROR 1\n");
        return 1;
    }

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    fclose(file);

    printf("Number of students in the file: %d\n", count);
    return 0;
}

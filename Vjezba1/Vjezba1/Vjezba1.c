#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 100
int main() {
    int count = 0;
	char ch[MAX] = { 0 };
    FILE* file = fopen("studenti.txt", "r");

    if (file == NULL) {
        printf("ERROR -1\n");
        return -1;
    }

	while (!feof(file))
	{
		fgets(ch, MAX, file);
		count++;
	}

    fclose(file);

    printf("Number of students in the file: %d\n", count);
    return 0;
}

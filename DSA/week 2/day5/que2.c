#include <stdio.h>
#include <string.h>

int compress(char* chars, int charsSize) {
    int i = 0;
    int index = 0;

    while (i < charsSize) {
        char current = chars[i];
        int count = 0;

        while (i < charsSize && chars[i] == current) {
            count++;
            i++;
        }

        chars[index++] = current;

        if (count > 1) {
            char temp[12];
            sprintf(temp, "%d", count);

            for (int j = 0; temp[j] != '\0'; j++) {
                chars[index++] = temp[j];
            }
        }
    }

    return index;
}

int main() {
    char chars[] = {'a','a','b','b','c','c','c'};
    int size = 7;

    int newSize = compress(chars, size);

    printf("Compressed String: ");
    for (int i = 0; i < newSize; i++) {
        printf("%c", chars[i]);
    }

    printf("\nLength = %d\n", newSize);

    return 0;
}
#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "eat";

    int freq[26] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        freq[str[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            printf("%c -> %d\n", 'a' + i, freq[i]);
        }
    }

    return 0;
}
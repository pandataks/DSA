#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool repeatedSubstringPattern(char *s) {
    int n = strlen(s);

    for (int len = 1; len <= n / 2; len++) {
        if (n % len != 0)
            continue;

        int ok = 1;

        for (int i = len; i < n; i++) {
            if (s[i] != s[i % len]) {
                ok = 0;
                break;
            }
        }

        if (ok)
            return true;
    }

    return false;
}

int main() {
    char s[] = "abab";

    if (repeatedSubstringPattern(s))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
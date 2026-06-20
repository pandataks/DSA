#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(char *s, char *t) {
    int i = 0, j = 0;

    while (s[i] && t[j]) {
        if (s[i] == t[j]) {
            i++;
        }
        j++;
    }

    return s[i] == '\0';
}

int main() {
    char s[] = "abc";
    char t[] = "ahbgdc";

    if (isSubsequence(s, t))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
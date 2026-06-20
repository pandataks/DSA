#include <stdio.h>

char* reverseWords(char* s) {
    int start = 0, end = 0;

    while (s[end]) {
        while (s[end] && s[end] != ' ')
            end++;

        int l = start;
        int r = end - 1;

        while (l < r) {
            char t = s[l];
            s[l] = s[r];
            s[r] = t;
            l++;
            r--;
        }

        if (s[end] == ' ') {
            end++;
            start = end;
        }
    }

    return s;
}

int main() {
    char s[] = "Let's take LeetCode contest";

    printf("%s\n", reverseWords(s));

    return 0;
}
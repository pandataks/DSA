#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char s[]) {

    int maxLen = 0;

    for(int i = 0; s[i] != '\0'; i++) {

        int count[256] = {0};
        int len = 0;

        for(int j = i; s[j] != '\0'; j++) {

            if(count[s[j]] == 1)
                break;

            count[s[j]] = 1;
            len++;
        }

        if(len > maxLen)
            maxLen = len;
    }

    return maxLen;
}

int main() {

    char s[] = "abcabcbb";

    printf("%d\n", lengthOfLongestSubstring(s));

    return 0;
}
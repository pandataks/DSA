#include <stdio.h>
#include <string.h>

void findAnagrams(char s[], char p[]) {

    int n = strlen(s);
    int m = strlen(p);

    if(m > n) {
        printf("No anagrams\n");
        return;
    }

    for(int i = 0; i <= n - m; i++) {

        int a[26] = {0};
        int b[26] = {0};

        for(int j = 0; j < m; j++) {
            a[p[j] - 'a']++;
            b[s[i + j] - 'a']++;
        }

        int ok = 1;

        for(int k = 0; k < 26; k++) {
            if(a[k] != b[k]) {
                ok = 0;
                break;
            }
        }

        if(ok == 1) {
            printf("%d ", i);
        }
    }
}

int main() {

    char s[] = "cbaebabacd";
    char p[] = "abc";

    printf("Anagram indices: ");
    findAnagrams(s, p);

    return 0;
}
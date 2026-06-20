#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool checkInclusion(char s1[], char s2[]) {

    int n1 = strlen(s1);
    int n2 = strlen(s2);

    if(n1 > n2)
        return false;

    for(int i = 0; i <= n2 - n1; i++) {

        int a[26] = {0};
        int b[26] = {0};

        for(int j = 0; j < n1; j++) {
            a[s1[j] - 'a']++;
            b[s2[i + j] - 'a']++;
        }

        int same = 1;

        for(int k = 0; k < 26; k++) {
            if(a[k] != b[k]) {
                same = 0;
                break;
            }
        }

        if(same)
            return true;
    }

    return false;
}

int main() {

    char s1[] = "ab";
    char s2[] = "eidbaooo";

    if(checkInclusion(s1, s2))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
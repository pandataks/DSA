#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* decodeString(char* s) {
    char *strStack[100];
    int numStack[100];
    int top = -1;

    char *cur = (char *)malloc(100000);
    cur[0] = '\0';

    int num = 0;

    for (int i = 0; s[i]; i++) {
        if (isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        else if (s[i] == '[') {
            top++;
            numStack[top] = num;
            strStack[top] = cur;

            cur = (char *)malloc(100000);
            cur[0] = '\0';
            num = 0;
        }
        else if (s[i] == ']') {
            char *tmp = (char *)malloc(100000);
            tmp[0] = '\0';

            for (int k = 0; k < numStack[top]; k++)
                strcat(tmp, cur);

            strcat(strStack[top], tmp);

            cur = strStack[top];
            top--;
        }
        else {
            int len = strlen(cur);
            cur[len] = s[i];
            cur[len + 1] = '\0';
        }
    }

    return cur;
}

int main() {
    char s[] = "3[a2[c]]";

    printf("%s\n", decodeString(s));

    return 0;
}
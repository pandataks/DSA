#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* parseTernary(char* expression) {
    int n = strlen(expression);

    char stack[10000];
    int top = -1;

    for (int i = n - 1; i >= 0; i--) {

        if (top >= 1 && stack[top] == '?') {

            top--;
            char first = stack[top--];
            top--;
            char second = stack[top--];

            if (expression[i] == 'T')
                stack[++top] = first;
            else if (expression[i] == 'F')
                stack[++top] = second;

        } else {
            stack[++top] = expression[i];
        }
    }

    char *result = (char *)malloc(2);
    result[0] = stack[top];
    result[1] = '\0';

    return result;
}

int main() {
    char expr[] = "T?2:3";

    char *ans = parseTernary(expr);

    printf("%s\n", ans);

    free(ans);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void solve(char **ans, int *size, char *cur, int pos, int open, int close, int n) {
    if (pos == 2 * n) {
        cur[pos] = '\0';
        ans[*size] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(ans[*size], cur);
        (*size)++;
        return;
    }

    if (open < n) {
        cur[pos] = '(';
        solve(ans, size, cur, pos + 1, open + 1, close, n);
    }

    if (close < open) {
        cur[pos] = ')';
        solve(ans, size, cur, pos + 1, open, close + 1, n);
    }
}

int main() {
    int n = 3;
    char *ans[100];
    int size = 0;
    char cur[20];

    solve(ans, &size, cur, 0, 0, 0, n);

    for (int i = 0; i < size; i++) {
        printf("%s\n", ans[i]);
    }

    return 0;
}
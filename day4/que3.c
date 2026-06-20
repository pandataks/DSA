#include <stdio.h>

int largestRectangleArea(int* heights, int heightsSize) {
    int stack[100000];
    int top = -1;
    int maxArea = 0;

    for (int i = 0; i <= heightsSize; i++) {

        int currHeight = (i == heightsSize) ? 0 : heights[i];

        while (top != -1 && heights[stack[top]] > currHeight) {
            int h = heights[stack[top--]];

            int width;
            if (top == -1)
                width = i;
            else
                width = i - stack[top] - 1;

            int area = h * width;

            if (area > maxArea)
                maxArea = area;
        }

        stack[++top] = i;
    }

    return maxArea;
}

int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};

    printf("%d\n", largestRectangleArea(heights, 6));

    return 0;
}
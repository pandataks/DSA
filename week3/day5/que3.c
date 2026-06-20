#include <stdio.h>
#include <stdlib.h>

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize) {

    int *result = (int*)malloc((numsSize - k + 1) * sizeof(int));

    int deque[100000];
    int front = 0, rear = -1;

    int idx = 0;

    for (int i = 0; i < numsSize; i++) {

        while (front <= rear && deque[front] <= i - k)
            front++;

        while (front <= rear && nums[deque[rear]] <= nums[i])
            rear--;

        deque[++rear] = i;

        if (i >= k - 1)
            result[idx++] = nums[deque[front]];
    }

    *returnSize = idx;
    return result;
}

int main() {

    int nums[] = {1,3,-1,-3,5,3,6,7};
    int size = 8;
    int k = 3;
    int returnSize;

    int *ans = maxSlidingWindow(nums, size, k, &returnSize);

    for (int i = 0; i < returnSize; i++)
        printf("%d ", ans[i]);

    free(ans);

    return 0;
}
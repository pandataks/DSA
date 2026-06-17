#include <stdio.h>
#include <stdlib.h>

int* nextGreaterElement(int* nums1, int nums1Size,
                        int* nums2, int nums2Size,
                        int* returnSize) {

    int *ans = (int*)malloc(nums1Size * sizeof(int));

    for (int i = 0; i < nums1Size; i++) {
        ans[i] = -1;

        for (int j = 0; j < nums2Size; j++) {

            if (nums2[j] == nums1[i]) {

                for (int k = j + 1; k < nums2Size; k++) {
                    if (nums2[k] > nums1[i]) {
                        ans[i] = nums2[k];
                        break;
                    }
                }

                break;
            }
        }
    }

    *returnSize = nums1Size;
    return ans;
}

int main() {
    int nums1[] = {4, 1, 2};
    int nums2[] = {1, 3, 4, 2};

    int returnSize;

    int *result = nextGreaterElement(
        nums1, 3,
        nums2, 4,
        &returnSize
    );

    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }

    free(result);

    return 0;
}
#include <stdio.h>

int removeDuplicates(int nums[], int n) {

    if(n == 0)
        return 0;

    int j = 0;

    for(int i = 1; i < n; i++) {

        if(nums[i] != nums[j]) {
            j++;
            nums[j] = nums[i];
        }
    }

    return j + 1;
}

int main() {

    int nums[] = {1, 1, 2, 2, 3, 4, 4};
    int n = sizeof(nums) / sizeof(nums[0]);

    int k = removeDuplicates(nums, n);

    printf("Number of unique elements = %d\n", k);

    printf("Array after removing duplicates: ");

    for(int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
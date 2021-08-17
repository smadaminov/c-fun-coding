#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

/*
 * Note: The returned array must be malloced, assume caller calls free().
 * This solution has O(N^2) time complexity
 */
int* twoSum_n2(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *result = (int*)malloc(*returnSize * sizeof(int));
    
    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return NULL;
}

/*
 * Note: The returned array must be malloced, assume caller calls free().
 * MSR: write down a faster solution
 */
int* twoSum_n(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    int *result = (int*)malloc(*returnSize * sizeof(int));
    
    for (int i = 0; i < numsSize - 1; ++i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    return NULL;
}

int main() {
    int nums_1[5] = {2,7,11,15};
    int target_1 = 9;
    int *returnSize = (int*)malloc(sizeof(int));
    int *res = twoSum_n2(nums_1, 4, target_1, returnSize);
    assert(res[0] + res[1] == 1);
    free(res);

    int nums_2[3] = {3, 2, 4};
    int target_2 = 6;
    res = twoSum_n2(nums_2, 3, target_2, returnSize);
    assert(res[0] + res[1] == 3);
    free(res);

    int nums_3[3] = {3, 3};
    int target_3 = 6;
    res = twoSum_n2(nums_3, 2, target_3, returnSize);
    assert(res[0] + res[1] == 1);
    free(res);

    free(returnSize);

    printf("Done!\n");

    return 0;
}

#include <assert.h>
#include <stddef.h>
#include <stdio.h>

int singleNumber(int* nums, int numsSize){
    int answer = 0;
    for (size_t i = 0; i < numsSize; ++i) {
        answer ^= nums[i];
    }

    printf("The answer is: %d\n", answer);
    return answer;
}

int main(void) {
    int nums[3] = {2, 2, 1};
    assert(singleNumber(nums, 3) == 1);
    int nums_2[5] = {4, 1, 2, 1, 2};
    assert(singleNumber(nums_2, 5) == 4);
    int nums_3[1] = {1};
    assert(singleNumber(nums_3, 1) == 1);
    return 0;
}

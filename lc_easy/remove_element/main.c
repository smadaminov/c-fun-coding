#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int forward_it = 0;
    int backward_it = numsSize - 1;
    int k = 0;
    while(backward_it >= 0 && nums[backward_it] == val) {
        backward_it--;
        k++;
    }
    while (forward_it <= backward_it) {
        if (nums[forward_it] == val) {
            int tmp = nums[forward_it];
            nums[forward_it] = nums[backward_it];
            nums[backward_it] = tmp;
            backward_it--;
            k++;
            while(backward_it >= forward_it && nums[backward_it] == val) {
                backward_it--;
                k++;
            }
        }
        forward_it++;
    }
    
    return numsSize - k;
}

int main(void) {
    int nums[] = {3, 2, 2, 3};
    int k = removeElement(nums, 4, 3);
    for (int i = 0; i < k - 1; ++i) {
        printf("%d ", nums[i]);
    }
    printf("%d\n", nums[k - 1]);

    int nums_2[] = {0, 1, 2, 2, 3, 0, 4, 2};
    k = removeElement(nums_2, 8, 2);
    for (int i = 0; i < k - 1; ++i) {
        printf("%d ", nums_2[i]);
    }
    printf("%d\n", nums_2[k - 1]);

    return 0;
}

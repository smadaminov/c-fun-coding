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


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct hash_cell {
    int is_empty;
    int key;
    int pos;
    struct hash_cell *next;
} hash_cell;

int get_hash_cell_index(int key, int hashSize) {
    int tmp = key;
    if (tmp < 0) tmp *= -1;
    return tmp % hashSize;
}

void hash_insert(int number, int cell_index, int pos, hash_cell *hash) {
    hash_cell *current = (hash_cell*)&hash[cell_index];
    printf("aloha -> %d\n", current->is_empty);
    while(current->is_empty == 0) {
        printf("-> %d\n", current->is_empty);
        current = current->next;
    }
    hash_cell *next = (hash_cell*)malloc(1 * sizeof(hash_cell));
    next->is_empty = 1;
    next->key = 0;
    next->pos = 0;
    next->next = NULL;
    
    current->key = number;
    current->next = next;
    current->pos = pos;
    current->is_empty = 0;
}

int hash_pos_retrieve(int key, int hashSize, hash_cell *hash, int pos) {
    int hash_cell_index = get_hash_cell_index(key, hashSize);
    hash_cell *current = &hash[hash_cell_index];
    while (current != NULL) {
        if (current->is_empty == 1) {
            return -1;
        }
        if (current->key == key && current->pos != pos) {
            printf("key: %d\n", current->key);
            printf("pos: %d\n", current->pos);
            return current->pos;
        }
        current = current->next;
    }
    
    return -1;
}

void hash_number(int number, int pos, int hashSize, hash_cell *hash) {
    int cell_index = get_hash_cell_index(number, hashSize);
    hash_insert(number, cell_index, pos, hash);
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    hash_cell *hash = (hash_cell*)malloc(numsSize * sizeof(hash_cell));
    for (int i = 0; i < numsSize; ++i) {
        hash[i].is_empty = 1;
        hash[i].key = 0;
        hash[i].pos = 0;
        hash[i].next = NULL;
    }
    
    for (int i = 0; i < numsSize; ++i) {
        hash_number(nums[i], i, numsSize, hash);
    }
    
    for (int i = 0; i < numsSize; ++i) {
        printf("target: %d\n", target-nums[i]);
        int ret = hash_pos_retrieve(target - nums[i], numsSize, hash, i);
        if (ret != -1) {
            int *indices = (int*)malloc(*returnSize * sizeof(int));
            indices[0] = i;
            indices[1] = ret;
            return indices;
        }
    }

    return NULL;
}

int main() {
    /*
    int nums_1[5] = {2,7,11,15};
    int target_1 = 9;*/
    int *returnSize = (int*)malloc(sizeof(int));/*
    int *res = twoSum(nums_1, 4, target_1, returnSize);
    assert(res[0] + res[1] == 1);
    free(res);

    int nums_2[3] = {3, 2, 4};
    int target_2 = 6;
    res = twoSum(nums_2, 3, target_2, returnSize);
    assert(res[0] + res[1] == 3);
    free(res);

    int nums_3[3] = {3, 3};
    int target_3 = 6;
    res = twoSum(nums_3, 2, target_3, returnSize);
    assert(res[0] + res[1] == 1);
    free(res);
    */

    int nums_4[4] = {-3, 4, 3, 90};
    int target_4 = 0;
    int *res = twoSum(nums_4, 4, target_4, returnSize);
    printf("%d and %d\n", res[0], res[1]);
    assert(res[0] + res[1] == 2);
    free(res);

    free(returnSize);

    printf("Done!\n");

    return 0;
}

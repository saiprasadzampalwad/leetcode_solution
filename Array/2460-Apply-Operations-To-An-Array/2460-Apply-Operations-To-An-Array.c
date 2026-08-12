/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* applyOperations(int* nums, int numsSize, int* returnSize) {
    int i;
    for (i = 0; i < numsSize - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }
    int* result = (int*)malloc(numsSize * sizeof(int));
    i = 0;
    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != 0) {
            result[i++] = nums[j];
        }
    }
    while (i< numsSize) {
        result[i++] = 0;
    }
    *returnSize = numsSize;
    return result;
}
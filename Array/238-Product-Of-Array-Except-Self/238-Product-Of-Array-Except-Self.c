/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int*answer=(int*)malloc(numsSize*sizeof(int));
      int* left_products = (int*)malloc(numsSize * sizeof(int));
    int* right_products = (int*)malloc(numsSize * sizeof(int));
    
    left_products[0] = 1;
    for (int i = 1; i < numsSize; i++) {
        left_products[i] = nums[i - 1] * left_products[i - 1];
    }
    
    right_products[numsSize - 1] = 1;
    for (int i = numsSize - 2; i >= 0; i--) {
        right_products[i] = nums[i + 1] * right_products[i + 1];
    }
    
    for (int i = 0; i < numsSize; i++) {
        answer[i] = left_products[i] * right_products[i];
    }
    
    free(left_products);
    free(right_products);
    
    *returnSize=numsSize;
    return answer;
}
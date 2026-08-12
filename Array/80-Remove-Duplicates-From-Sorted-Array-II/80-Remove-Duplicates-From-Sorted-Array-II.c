int removeDuplicates(int* nums, int numsSize) {

    int i=2;
    if(numsSize<i)
    return numsSize;
    for (int j = 2; j < numsSize;j++) {
        if (nums[j] !=nums[i-2]) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}
    int findMin(int* nums, int numsSize) {
    int min =*nums;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]<min)
        {
            min=nums[i];

        }

    }
    return min;
}

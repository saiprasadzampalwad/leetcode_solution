int findPeakElement(int* nums, int numsSize) {
    int ind=0;
    for(int i=0;i<numsSize;i++)
    {
        if (nums[ind]<nums[i])
        {

            ind=i;
        }
    }
    return ind;
}
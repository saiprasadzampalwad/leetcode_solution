/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void sort(int *nums,int n)
{
    int min,temp;
    for(int i=0;i<n;i++)
    {
        min=i;
        for(int j=i+1;j<n;j++)
        {
            if(nums[min]>nums[j])
            {
                min=j;
            }
        }
        if(i!=min)
        {
            temp=nums[min];
            nums[min]=nums[i];
            nums[i]=temp;
        }
    }

}
int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int* a = (int*)malloc(numsSize * sizeof(int));
    for(int i=0;i<numsSize;i++)
    {
        a[i]=nums[i]*nums[i];
    }
    sort(a,numsSize);
    *returnSize=numsSize;
    return a;
}
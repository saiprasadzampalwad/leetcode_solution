/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
   int *a=(int*)malloc(2*sizeof(int));
   a[0]=-1;
   a[1]=-1;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==target)
        {
            a[0]=i;
            break;
        }   
    }
     for(int i=numsSize-1;i>=0;i--)
    {
        if(nums[i]==target)
        {
            a[1]=i;
            break;
            
        }   
    }
    *returnSize=2;
    return a;
}
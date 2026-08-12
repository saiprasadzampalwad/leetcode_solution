/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    for(int i=0,j=numbersSize-1;i<j;)
    {
            if(numbers[i]+numbers[j]==target)
            {int *result=(int*)malloc(2*sizeof(int));
                result[0]=i+1;
                result[1]=j+1;
                *returnSize=2;
                return result;
            }
              else if((numbers[i]+numbers[j])>target)
            {
                j--;
            }

            else
            {
                i++;
            }
        
    }
    *returnSize=0;
    return NULL;
}
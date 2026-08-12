class Solution {
    public boolean canJump(int[] nums) {
        int p=0;
        for (int i : nums)
           { if(p<0)
                return false;
            else if(i>p)
               p=i;
            p-=1;
           }   
        return true;
    }
}
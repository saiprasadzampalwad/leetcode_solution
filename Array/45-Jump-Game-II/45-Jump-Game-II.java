class Solution {
    public int jump(int[] nums) {
       int l=0;
       int r=0;
        int jump=0;
        while (r<nums.length-1){
           int m=0;
            for(int i=l;i<r+1;i++){
                if(m<i+nums[i])
                    m=i+nums[i];
            }
            l=r+1;
            r=m;
            jump+=1;
        }
        return jump;
    }
}
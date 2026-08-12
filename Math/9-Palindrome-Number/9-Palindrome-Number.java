class Solution {
    public boolean isPalindrome(int x) {
        int n,temp=x;
        long num=0;

        if(x>=0)
        {
         while(x!=0)
            {
                n=x%10;
                num=(num*10)+n;
                x=x/10;
            }
           
            return temp==num;
        }
        return false;
    }
}
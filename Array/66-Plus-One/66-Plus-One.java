class Solution {
    public int[] plusOne(int[] digits) {
        int carry=1;
     for(int i=digits.length-1;i>=0;i--)
     { int sum=0;
        sum=digits[i]+carry;
        if(sum>9)
        {
            digits[i]=sum%10;
            carry=sum/10;
        }
        else{
            digits[i]=sum;
            carry=0;
        }
    
     }
    if(carry==1)
    {
        int[] rdigits =new int[digits.length+1];
        rdigits[0]=1;
        return rdigits;
    }
     return digits;
    }
}
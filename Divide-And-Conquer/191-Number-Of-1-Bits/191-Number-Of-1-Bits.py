class Solution:
    def hammingWeight(self, n: int) -> int:
        a=bin(n)
        count=0
        for num in a:
            if num=='1':
                count+=1
        return count
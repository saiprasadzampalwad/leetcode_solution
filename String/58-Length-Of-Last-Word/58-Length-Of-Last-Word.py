class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        word=s.split( )
        word.reverse()
        lenth=len(word[0])
        return lenth
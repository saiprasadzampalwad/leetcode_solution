int lengthOfLongestSubstring(char* s) {
   int n = strlen(s);
    int maxLength = 0;
    int start = 0;
    int charIndex[128] = {0};  

    for (int end = 0; end < n; end++) {
        char currentChar = s[end];
        if (charIndex[currentChar] > start) {
            start = charIndex[currentChar];
        }
        charIndex[currentChar] = end + 1;
        maxLength = (end - start + 1 > maxLength) ? end - start + 1 : maxLength;
    }

    return maxLength;
}
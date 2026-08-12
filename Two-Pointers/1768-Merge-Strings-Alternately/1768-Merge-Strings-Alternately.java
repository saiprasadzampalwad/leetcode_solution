class Solution {
    public String mergeAlternately(String word1, String word2) {
        char[] arr1 = word1.toCharArray();
        char[] arr2 = word2.toCharArray();
        char[] res = new char[word1.length() + word2.length()];

        int i = 0, j = 0, k = 0;

        while (i < arr1.length || j < arr2.length) {
            if (i < arr1.length) {
                res[k++] = arr1[i++];
            }
            if (j < arr2.length) {
                res[k++] = arr2[j++];
            }
        }

        return new String(res);
    }
}
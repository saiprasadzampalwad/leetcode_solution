class Solution {
    public String multiply(String num1, String num2) {
       
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }

        int m = num1.length();
        int n = num2.length();

        int[] result = new int[m + n];

        // Traverse from right to left (just like Python code)
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                int digit1 = num1.charAt(i) - '0';
                int digit2 = num2.charAt(j) - '0';

                int mul = digit1 * digit2;

                int pos1 = i + j;
                int pos2 = i + j + 1;

                int total = mul + result[pos2];

                result[pos2] = total % 10;
                result[pos1] += total / 10;
            }
        }

        // Convert result array to string
        StringBuilder sb = new StringBuilder();
        for (int val : result) {
            sb.append(val);
        }

        // Remove leading zeros
        String resultStr = sb.toString().replaceFirst("^0+(?!$)", "");

        return resultStr;
    }
}

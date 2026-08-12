class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int sum = 0;
        int min = nums.length + 1;
        int l = 0;
        for (int r = 0; r < nums.length; r++) {
            sum += nums[r];
            while (sum >= target) {
                if (min > r - l + 1)
                    min = r - l + 1;
                sum -= nums[l++];
            }
        }
        if (min < nums.length + 1)
            return min;
        return 0;
    }
}
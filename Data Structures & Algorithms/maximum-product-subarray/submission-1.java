class Solution {
    public int maxProduct(int[] nums) {
        int n = nums.length;
        int currMin = 1;
        int currMax = 1;

        int res = nums[0];

        for(int num: nums) {
            int tmp1 = num * currMax;
            int tmp2 = num * currMin;

            currMax = Math.max(Math.max(tmp1, tmp2), num);
            currMin = Math.min(Math.min(tmp1, tmp2), num);

            res = Math.max(currMax, res);
        }

        return res;
    }
}

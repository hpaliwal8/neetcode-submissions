class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        if (n == 1) return false;

        for(int num: nums) {
            sum += num;
        }

        if(sum % 2 != 0) return false;
        int target = sum / 2;

        vector<vector<bool>> dp (n + 1, vector<bool>( sum / 2 + 1, false));

        // When target is 0, store true
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j<= target; j++) {
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j] || // not take
                     dp[i-1][j - nums[i-1]]; // take
                } else {
                    dp[i][j] = dp[i-1][j]; //not take
                }
            }
        }

        return dp[n][target];
    }
};

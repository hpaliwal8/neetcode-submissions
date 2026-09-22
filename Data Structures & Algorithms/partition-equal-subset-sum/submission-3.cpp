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

        unordered_set<int> dp;
        dp.insert(0);

        for(int num: nums) {
            unordered_set<int> nextDp = dp;
            for(int t: dp) {
                if(t + num == target) {
                    return true;
                }
                nextDp.insert(t+num);
                nextDp.insert(num);
            }
            dp = nextDp;
        }

        return false;
    }
};

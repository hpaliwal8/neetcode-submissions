class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;

        helper(nums, 0, result, subset);
        return result;
    }

    void helper(vector<int>& nums, int i, vector<vector<int>>& res, vector<int>& sub) {
        if(i >= nums.size()) {
            res.push_back(sub);
            return;
        }

        // include 
        sub.push_back(nums[i]);
        helper(nums, i+1, res, sub);

        // do not include
        sub.pop_back();
        helper(nums, i+1, res, sub);
    }
};

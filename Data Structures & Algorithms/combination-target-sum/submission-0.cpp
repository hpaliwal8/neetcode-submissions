class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        dfs(nums, 0, result, temp, target);

        return result;
    }

    void dfs(vector<int>& nums, int i, vector<vector<int>>& result, vector<int>& temp, int target) {
        if(i >= nums.size() || target < 0) {
            return;
        } else if(target == 0) {
            result.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        dfs(nums, i, result, temp, target - nums[i]);

        temp.pop_back();
        dfs(nums, i+1, result, temp, target);
    }
};

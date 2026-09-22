class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> sub;

        sort(nums.begin(), nums.end());

        dfs(nums, 0, sub, res, target);

        return res;
    }

    void dfs(vector<int>& nums, int i, vector<int>& sub, vector<vector<int>>& res, int target) {
        if(target == 0) {
            res.push_back(sub);
            return;
        }
        if(i == nums.size() || target < 0) {
            return;
        }

        // Add to list
        sub.push_back(nums[i]);
        dfs(nums, i+1, sub, res, target - nums[i]);

        // Do not add to list (already analyzed)
        sub.pop_back();

        while(i+1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
        
        dfs(nums, i+1, sub, res, target);
    }
};

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;

        sort(nums.begin(), nums.end());
        backtrack(nums, res, sub, 0);
        return res;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& sub, int i) {
        if(i == nums.size()) {
            res.push_back(sub);
            return;
        }

        // take
        sub.push_back(nums[i]);
        backtrack(nums, res, sub, i+1);

        // dont take (or already analyzed)
        sub.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i+1]) {
            i++;
        }
        backtrack(nums, res, sub, i+1);
    }
};

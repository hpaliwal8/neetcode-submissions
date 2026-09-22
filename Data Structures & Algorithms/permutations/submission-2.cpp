class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub;
        vector<bool> pick(nums.size());

        backtrack(nums, res, sub, pick);

        return res;
    }

    void backtrack(vector<int>& nums, vector<vector<int>>& res, vector<int>& sub, vector<bool>& pick) {
        if(sub.size() == nums.size()) {
            res.push_back(sub);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if(!pick[i]) {
                pick[i] = true;
                sub.push_back(nums[i]);
                backtrack(nums, res, sub, pick);

                pick[i] = false;
                sub.pop_back();
            }
        }
    }

};

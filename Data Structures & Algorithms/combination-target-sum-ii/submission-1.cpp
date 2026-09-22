class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> sub;

        sort(candidates.begin(), candidates.end());
        backtrack(candidates, res, sub, target, 0);

        return res;
    }

    void backtrack(vector<int>& candidates, vector<vector<int>>& res, vector<int>& sub, int target, int i) {
        if(target == 0) {
            res.push_back(sub);
            return;
        }

        if(target < 0 || i >= candidates.size()) {
            return;
        }

        sub.push_back(candidates[i]);
        backtrack(candidates, res, sub, target - candidates[i], i + 1);

        while(i + 1 <= candidates.size() && candidates[i+1] == candidates[i]) {
            i++;
        }

        sub.pop_back();
        backtrack(candidates, res, sub, target, i + 1);
    }
};

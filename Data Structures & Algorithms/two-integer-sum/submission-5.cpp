class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexDict;
        for (int i=0;i<nums.size();i++) {
            int y = target - nums[i];
            if (indexDict.contains(y)) {
                return {indexDict[y], i};
            }
            else {
                indexDict[nums[i]] = i;
            }
        }

        return {-1, -1};
    }
};

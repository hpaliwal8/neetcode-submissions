class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexDict;
        for (int i=0;i<nums.size();i++) {
            if (indexDict.count(target - nums[i])) {
                return vector<int>{indexDict[target - nums[i]], i};
            }
            else {
                indexDict[nums[i]] = i;
            }
        }

        return vector<int>{-1, -1};
    }
};

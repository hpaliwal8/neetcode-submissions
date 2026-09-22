#include <algorithm> 

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int> seen(nums.begin(), nums.end());
        // cout << minElement << " " << maxElement << endl;

        int res = 0;
        for(const int& num: nums) {
            int nu = num;
            if(!seen.contains(nu - 1)) {
                int temp = 1;
                while (seen.contains(nu + 1)) {
                    temp += 1;
                    nu += 1;
                }

                res = max(res, temp);
            }
        }

        return res;
    }
};

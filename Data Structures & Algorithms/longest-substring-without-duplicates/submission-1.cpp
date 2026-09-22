class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0 || s.size() == 1) {
            return s.size();
        }
        int n = s.size();

        int left = 0;
        int res = 0;
        unordered_set<char> seen;

        for(int right=0;right<n;right++) {
            while (seen.contains(s[right])) {
                seen.erase(s[left]);
                left += 1;
            }

            seen.insert(s[right]);
            res = max(res, right - left + 1);
        }

        return res;
        
    }
};

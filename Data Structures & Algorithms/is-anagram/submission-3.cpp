class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> charCount;
        
        for (char c1: s) {
            charCount[c1] += 1;
        }

        for (char c2: t) {
            charCount[c2] -= 1;
        }

        for (const auto& [key, value]: charCount) {
            if (value != 0) {
                return false;
            }
        }

        return true;
    }
};

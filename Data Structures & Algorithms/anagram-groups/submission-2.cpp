class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strDict;

        for(string str: strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            strDict[temp].push_back(str);
        }
        vector<vector<string>> res;
        for(const auto& [key, value]: strDict) {
            res.push_back(value);
        }

        return res;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> strDict;

        for(string str: strs) {
            string temp = str;
            sort(temp.begin(), temp.end());

            if (!strDict.contains(temp)) {
                strDict[temp] = {};
            }

            strDict[temp].push_back(str);
        }
        vector<vector<string>> res;
        for(const auto& [key, value]: strDict) {
            vector<string> temp;
            for (const auto& v: value) {
                temp.push_back(v);
            }
            res.push_back(temp);
        }

        return res;
    }
};

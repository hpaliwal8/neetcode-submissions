class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counter;
        for(const auto& num: nums) {
            counter[num] += 1;
        }

        auto comp = [&counter](int key1, int key2) {
            return counter.at(key1) < counter.at(key2);
        };

        priority_queue<int, vector<int>, decltype(comp)> maxHeap(comp);

        for(const auto& [key, value]: counter) {
            maxHeap.push(key);
        }

        vector<int> res;
        for (int i=0;i<k;i++) {
            auto temp = maxHeap.top();
            cout << temp << endl;
            maxHeap.pop();
            res.push_back(temp);
        }
        return res;
    }
};

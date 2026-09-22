class Solution {
public:
    int getDistanceFromOrigin(const vector<int>& a) {
        return (a[0] * a[0] + a[1] * a[1]);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto compare = [&](const vector<int>& a, const vector <int>& b) {
            return getDistanceFromOrigin(a) > getDistanceFromOrigin(b); 
        };

        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)> pq(compare);

        for(const vector<int>& point: points) {
            pq.push(point);
        }

        vector<vector<int>> res;
        while(k-- > 0) {
            res.push_back(pq.top());
            pq.pop();
        }

        return res;
    }
};

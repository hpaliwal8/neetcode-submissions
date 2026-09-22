class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;

        queue<pair<int, int>> q;

        vector<int> count(26, 0);
        for(char task: tasks) {
            count[task - 'A']++;
        }

        for(int cnt: count) {
            if(cnt > 0) {
                pq.push(cnt);
            }
        }

        int time = 0;

        while(!pq.empty() || !q.empty()) {
            time++;

            if(!pq.empty()) {
                int element = pq.top() - 1;
                pq.pop();
                if(element > 0){
                    q.push({element, time + n});
                }
            } else {
                time = q.front().second;
            }

            if(!q.empty() && q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
        }

        return time;
    }
};

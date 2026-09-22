class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n - 1;

        while(left < right) {
            int ts = numbers[left] + numbers[right];
            if(target == ts) {
                return vector<int>{left + 1, right + 1};
            } else if (ts < target) {
                left += 1;
            } else {
                right -= 1;
            }
        }

        return vector<int>{-1, -1};
    }
};

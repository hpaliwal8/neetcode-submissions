class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixProduct(n+1, 1);
        vector<int> suffixProduct(n+1, 1);

        for (int i=0;i<n;i++) {
            int p_adjustement = i + 1;
            prefixProduct[p_adjustement] = prefixProduct[p_adjustement-1] * nums[i];
            suffixProduct[n-i-1] = suffixProduct[n-i] * nums[n-i-1];

        }

        vector<int> res(n, 1);
        for (int i=0;i<n;i++) {
            res[i] = prefixProduct[i] * suffixProduct[i + 1];
        }

        return res;
    }
};

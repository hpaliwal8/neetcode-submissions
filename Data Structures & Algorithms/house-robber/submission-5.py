class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        # self.cache = {}
        # def helper(index):
        #     if index > n - 1:
        #         return 0
            
        #     if index in self.cache:
        #         return self.cache[index]

        #     take = nums[index] + helper(index + 2)
        #     skip = helper(index + 1)

        #     self.cache[index] =  max(take, skip)
        #     return self.cache[index]

        # return helper(0)
        
        # TC: O(n)
        # SC: O(n) for cache + O(n/2) for recursive stack space

        dp = [0] * (n+2)
        dp[n] = dp[n+1] = 0

        for i in range(n-1, -1, -1):
            dp[i] = max(nums[i] + dp[i+2], dp[i+1])

        return dp[0]

class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        # self.cache = {}
        # def helper(index, rem):
        #     if index == n:
        #         return 1 if rem == 0 else 0

        #     if (index, rem) in self.cache:
        #         return self.cache[(index, rem)]

        #     plus = helper(index + 1, rem + nums[index])
        #     minus = helper(index + 1, rem - nums[index])

        #     self.cache[(index, rem)] = plus + minus
        #     return self.cache[(index, rem)]

        # return helper(0, target)


        dp = [defaultdict(int) for _ in range(n + 1)]
        dp[n][0] = 1

        for i in range(n-1, -1, -1):
            for total, count in dp[i + 1].items():
                dp[i][total + nums[i]] += count
                dp[i][total - nums[i]] += count

        return dp[0][target]

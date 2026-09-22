class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        nc = len(coins)
        # self.cache = {}
        # def helper(index, rem):
        #     if rem == 0:
        #         return 1

        #     if rem < 0 or index == nc:
        #         return 0

        #     if (index, rem) in self.cache:
        #         return self.cache[(index, rem)]

        #     take = helper(index, rem - coins[index])
        #     not_take = helper(index + 1, rem)

        #     self.cache[(index, rem)] = take + not_take
        #     return self.cache[(index, rem)]

        # return helper(0, amount)

        dp = [[0] * (amount + 1) for _ in range(nc + 1)]

        for i in range(nc + 1):
            dp[i][0] = 1

        for i in range(nc-1, -1, -1):
            for j in range(1, amount + 1):
                take = dp[i][j - coins[i]] if j - coins[i] >= 0 else 0
                not_take = dp[i+1][j]
                dp[i][j] = take + not_take

        return dp[0][amount]


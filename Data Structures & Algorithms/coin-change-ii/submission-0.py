class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        nc = len(coins)
        self.cache = {}
        def helper(index, rem):
            if rem == 0:
                return 1

            if rem < 0 or index == nc:
                return 0

            if (index, rem) in self.cache:
                return self.cache[(index, rem)]

            take = helper(index, rem - coins[index])
            not_take = helper(index + 1, rem)

            self.cache[(index, rem)] = take + not_take
            return self.cache[(index, rem)]

        return helper(0, amount)
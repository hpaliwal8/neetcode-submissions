class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        self.cache = {}
        def helper(index, rem):
            if index == n:
                return 1 if rem == 0 else 0

            if (index, rem) in self.cache:
                return self.cache[(index, rem)]

            plus = helper(index + 1, rem + nums[index])
            minus = helper(index + 1, rem - nums[index])

            self.cache[(index, rem)] = plus + minus
            return self.cache[(index, rem)]

        return helper(0, target)

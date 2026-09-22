class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        self.cache = {}
        def helper(index):
            if index > n - 1:
                return 0
            
            if index in self.cache:
                return self.cache[index]

            take = nums[index] + helper(index + 2)
            skip = helper(index + 1)

            self.cache[index] =  max(take, skip)
            return self.cache[index]

        return helper(0)
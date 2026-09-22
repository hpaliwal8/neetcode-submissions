class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        self.res = 0
        self.cache = [[-1] * (n+1) for _ in range(n+1)]
        def helper(index, prev_index):
            if index == n:
                return 0

            if self.cache[index][prev_index + 1] != -1:
                return self.cache[index][prev_index + 1]
            
            take = 0
            prev_val = nums[prev_index] if prev_index >= 0 else float('-inf') 
            if prev_val < nums[index]:
                take += 1 + helper(index + 1, index)

            not_take = helper(index + 1, prev_index)

            self.cache[index][prev_index + 1] = max(take, not_take)
            return self.cache[index][prev_index + 1]

        
        return helper(0, -1)


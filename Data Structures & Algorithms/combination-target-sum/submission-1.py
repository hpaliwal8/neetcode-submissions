class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        nums.sort()

        def dfs(temp, i, total):
            if total == target:
                res.append(temp.copy())
                return

            if total > target or i >= len(nums):
                return

            for j in range(i, len(nums)):
                temp.append(nums[j])
                dfs(temp, j, total + nums[j])
                temp.pop()

        dfs([], 0, 0)
        return res
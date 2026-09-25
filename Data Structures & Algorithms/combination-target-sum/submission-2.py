class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        res = []
        nums.sort()

        def dfs(index, temp, total):
            if total == target:
                res.append(temp[:])
                return

            if total > target or index >= len(nums):
                return

            for j in range(index, len(nums)):
                temp.append(nums[j])
                dfs(j, temp, total + nums[j])
                temp.pop()

            # dfs(index + 1, temp, total)

        dfs(0, [], 0)
        return res
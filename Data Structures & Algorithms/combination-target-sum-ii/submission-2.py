class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res = []

        def dfs(temp, i, total):
            if total == target:
                res.append(temp.copy())
                return
            
            if total > target or i >= len(candidates):
                return

            for j in range(i, len(candidates)):
                if j > i and candidates[j] == candidates[j-1]:
                    continue
                temp.append(candidates[j])
                dfs(temp, j + 1, total + candidates[j])
                temp.pop()

        dfs([], 0, 0)
        return res
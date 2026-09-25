class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res = []
        candidates.sort()

        def dfs(temp, idx, total):
            if total == target:
                res.append(temp[:])
                return

            if total > target or idx >= len(candidates):
                return 

            for j in range(idx, len(candidates)):
                if j > idx and candidates[j] == candidates[j-1] :
                    continue

                temp.append(candidates[j])
                dfs(temp, j + 1, total + candidates[j])
                temp.pop()

        dfs([], 0, 0)
        return res
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        
        candidates.sort()
        res = []
        subset = []

        def dfs(first, total):

            if total == target:
                res.append(subset.copy())
                return

            for i in range(first, len(candidates)):

                if i > first and candidates[i] == candidates[i-1]:
                    continue

                if total + candidates[i] > target:
                    break

                subset.append(candidates[i])

                dfs(i + 1, total + candidates[i])

                subset.pop()

        dfs(0,0)

        return res
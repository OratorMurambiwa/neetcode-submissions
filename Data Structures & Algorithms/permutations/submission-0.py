class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        res = []
        permutations = []

        def dfs():
            if len(permutations) == len(nums):
                res.append(permutations.copy())
                return

            for num in nums:

                if num in permutations:
                    continue
                    
                permutations.append(num)

                dfs()

                permutations.pop()

        dfs()

        return res

        
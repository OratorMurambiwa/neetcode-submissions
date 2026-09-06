class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:

        l, r = 1, max(piles)
        
        k = r

        while l <= r:
            mid = (l + r) // 2
            
            total_hours = 0
            for pile in piles:
                total_hours += (pile + mid -1) // mid
            if total_hours <= h:
                k = mid
                r = mid -1

            else: 
                l = mid + 1

        return k
        
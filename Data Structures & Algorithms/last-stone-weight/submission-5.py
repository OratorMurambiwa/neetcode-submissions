class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        
        for i in range(len(stones)):
            stones[i] = -stones[i]

        heapq.heapify(stones)

        while len(stones) > 1:

            first = - heapq.heappop(stones)
            second = - heapq.heappop(stones)

            if first != second:
                new_stone = first - second
                heapq.heappush(stones, -new_stone)

        if stones:
            return - stones[0]

        return 0




        
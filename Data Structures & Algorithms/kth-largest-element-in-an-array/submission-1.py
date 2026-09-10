class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:

        for i in range(len(nums)):
            nums[i] = -nums[i]

        maxheap = nums
        heapq.heapify(maxheap)

        for i in range(k - 1):
            heapq.heappop(maxheap)

        return -maxheap[0]

        

            
        
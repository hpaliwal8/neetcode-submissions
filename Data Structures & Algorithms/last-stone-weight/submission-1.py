from heapq import heappush, heappop
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        pq = []

        for stone in stones:
            heappush(pq, -stone)
        
        res = 0
        while pq:
            if len(pq) < 2:
                break
            first = heappop(pq)
            second = heappop(pq)
            if first != second:
                heappush(pq, first - second)

        return -pq[0] if len(pq) > 0 else 0
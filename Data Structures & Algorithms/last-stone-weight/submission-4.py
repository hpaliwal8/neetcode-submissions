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
            print(pq)
            first = pq[0]
            heappop(pq)
            second = pq[0]
            heappop(pq)
            if first != second:
                heappush(pq, first - second)

        return -pq[0] if len(pq) > 0 else 0
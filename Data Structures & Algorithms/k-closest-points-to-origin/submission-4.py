from heapq import heappush, heappop
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        pq = []

        for x1, y1 in points:
            # print(x1, y1)
            heappush(pq, (-math.sqrt(x1**2 + y1**2), x1, y1))
            # print(pq)

            while len(pq) > k:
                heappop(pq)

        res = []
        # print(pq)
        while pq:
            ele = heappop(pq)
            # print(ele)
            res.append([ele[1], ele[2]])
        return res
        
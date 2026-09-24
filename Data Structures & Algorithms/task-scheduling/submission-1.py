from heapq import heappush, heappop
class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        pq = []
        time = 0
        counter = defaultdict(int)
        for task in tasks:
            counter[task] += 1

        for val in counter.values():
            heappush(pq, -val)

        q = deque() # this is holding [-cnt, idleTime]

        while pq or q:
            time += 1

            if pq:
                cnt = heappop(pq)
                newCnt = 1 + cnt

                if newCnt < 0:
                    q.append([newCnt, time + n])

            else:
                time = q[0][1]

            if q and q[0][1] == time:
                heappush(pq, q.popleft()[0])

        return time

            


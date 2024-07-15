# https://neetcode.io/problems/find-median-in-a-data-stream
# https://leetcode.com/problems/find-median-from-data-stream/

from typing import List
import heapq


class MedianFinder:

    def __init__(self):
        self.large = []
        self.small = []

    def addNum(self, num: int) -> None:
        if self.large and num > self.large[0]:
            heapq.heappush(self.large, num)
        else:
            heapq.heappush(self.small, -num)

        if len(self.large) - len(self.small) > 1:
            temp = heapq.heappop(self.large)
            heapq.heappush(self.small, -temp)
        elif len(self.large) - len(self.small) < -1:
            temp = heapq.heappop(self.small)
            heapq.heappush(self.large, -temp)

    def findMedian(self) -> float:
        if len(self.large) > len(self.small):
            return self.large[0]
        elif len(self.large) < len(self.small):
            return -self.small[0]
        else:
            return (-self.small[0] + self.large[0]) / 2.0


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()

# https://neetcode.io/problems/kth-largest-integer-in-a-stream
# https://leetcode.com/problems/kth-largest-element-in-a-stream/

from typing import List
import heapq


class KthLargest:
    def __init__(self, k: int, nums: List[int]):
        self.hp = nums
        heapq.heapify(self.hp)
        self.k = k
        while len(self.hp) > k:
            heapq.heappop(self.hp)

    def add(self, val: int) -> int:
        heapq.heappush(self.hp, val)
        if len(self.hp) > self.k:
            heapq.heappop(self.hp)
        return self.hp[0]

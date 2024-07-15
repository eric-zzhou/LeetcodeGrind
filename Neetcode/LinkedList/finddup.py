# https://neetcode.io/problems/find-duplicate-integer
# https://leetcode.com/problems/find-the-duplicate-number/

from typing import List


class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        slow, fast = 0, 0
        while True:
            slow, fast = nums[slow], nums[nums[fast]]
            if slow == fast:
                break

        slow2 = 0
        while slow != slow2:
            slow, slow2 = nums[slow], nums[slow2]
        return slow

    def findDuplicate(self, nums: List[int]) -> int:
        tr = set()
        for n in nums:
            if n in tr:
                return n
            tr.add(n)

# https://neetcode.io/problems/binary-search
# https://leetcode.com/problems/binary-search/

from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        if not nums:
            return -1

        mid = len(nums) // 2
        if target == nums[mid]:
            return mid
        elif target < nums[mid]:
            return self.search(nums[:mid], target)
        else:
            res = self.search(nums[mid + 1 :], target)
            return (mid + 1 + res) if res != -1 else -1

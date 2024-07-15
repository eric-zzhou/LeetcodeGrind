# https://neetcode.io/problems/find-minimum-in-rotated-sorted-array
# https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        l, r = 0, len(nums) - 1
        ret = 1001

        while l < r:
            m = l + (r - l) // 2
            if nums[m] > nums[r]:
                l = m + 1
            else:
                ret = min(ret, nums[m])
                r = m - 1
        return min(ret, nums[l])

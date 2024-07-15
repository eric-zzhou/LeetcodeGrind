# https://neetcode.io/problems/trapping-rain-water
# https://leetcode.com/problems/trapping-rain-water/

from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        ret = 0
        l, r = 0, len(height) - 1
        ml, mr = 0, 0
        while l < r:
            if height[l] < height[r]:
                ml = max(ml, height[l])
                ret += max(ml - height[l], 0)
                l += 1
            else:
                mr = max(mr, height[r])
                ret += mr - height[r]
                r -= 1
        return ret

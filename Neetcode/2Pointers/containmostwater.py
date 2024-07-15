# https://neetcode.io/problems/max-water-container
# https://leetcode.com/problems/container-with-most-water/

from typing import List


class Solution:
    def maxArea(self, heights: List[int]) -> int:
        ret = 0
        l, r = 0, len(heights) - 1
        while l < r:
            if heights[l] < heights[r]:
                ret = max(ret, heights[l] * (r - l))
                l += 1
            else:
                ret = max(ret, heights[r] * (r - l))
                r -= 1
        return ret

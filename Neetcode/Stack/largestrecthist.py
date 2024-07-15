# https://neetcode.io/problems/largest-rectangle-in-histogram
# https://leetcode.com/problems/largest-rectangle-in-histogram/

from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        prev = ret = heights[0]
        st = [(prev, 0)]
        for i, curr in enumerate(heights[1:]):
            if curr > prev:
                st.append((curr, i + 1))
            elif curr < prev:
                while st and st[-1][0] > curr:
                    th, ti = st.pop()
                    ret = max(ret, th * (i - ti + 1))
                st.append((curr, ti))
            prev = curr

        l = len(heights)
        for h, i in st:
            ret = max(ret, h * (l - i))
        return ret

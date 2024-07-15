# https://neetcode.io/problems/daily-temperatures
# https://leetcode.com/problems/daily-temperatures/

from typing import List


class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        ret = [0] * len(temperatures)
        st = []
        for i, curr in enumerate(temperatures):
            while st and st[-1][0] < curr:
                _, ind = st.pop()
                ret[ind] = i - ind
            st.append((curr, i))
        return ret

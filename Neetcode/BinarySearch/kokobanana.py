# https://neetcode.io/problems/eating-bananas
# https://leetcode.com/problems/koko-eating-bananas/

from typing import List
from math import ceil


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        l, r = 1, max(piles)
        ret = r
        while l <= r:
            m = l + (r - l) // 2
            spd = 0
            for pile in piles:
                spd += ceil(pile / m)
            if spd <= h:
                r = m - 1
                ret = m
            else:
                l = m + 1
        return ret

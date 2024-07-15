# https://neetcode.io/problems/buy-and-sell-crypto
# https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        currmin = 10001
        ret = 0
        for p in prices:
            if p < currmin:
                currmin = p
            else:
                ret = max(ret, p - currmin)
        return ret

# https://neetcode.io/problems/maximum-product-subarray
# https://leetcode.com/problems/maximum-product-subarray/

from typing import List


class Solution:
    def maxProduct(self, a: List[int]) -> int:
        b = a[::-1]
        for i in range(1, len(a)):
            a[i] *= a[i - 1] or 1
            b[i] *= b[i - 1] or 1
        return max(a + b)


class WorseSolution:
    def maxProduct(self, nums: List[int]) -> int:
        ret = nums[0]
        ma = mi = 1

        for n in nums:
            temp = ma * n
            ma = max(ma * n, mi * n, n)
            mi = min(temp, mi * n, n)
            ret = max(ma, ret)
        return ret

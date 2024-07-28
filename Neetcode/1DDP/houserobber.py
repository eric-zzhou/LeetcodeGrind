# https://neetcode.io/problems/house-robber
# https://leetcode.com/problems/house-robber/

from typing import List


class Solution:
    def rob(self, nums):
        rob1, rob2 = 0, 0
        for n in nums:
            rob1, rob2 = rob2, max(rob1 + n, rob2)
        return rob2


class WorseSolution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        nums[1] = max(nums[1], nums[0])
        for i in range(2, n):
            nums[i] = max(nums[i] + nums[i - 2], nums[i - 1])
        return nums[n - 1]

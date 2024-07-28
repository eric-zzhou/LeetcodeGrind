# https://neetcode.io/problems/house-robber-ii
# https://leetcode.com/problems/house-robber-ii/

from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        def helper(arr):
            rob1 = rob2 = 0
            for n in arr:
                rob1, rob2 = rob2, max(rob1 + n, rob2)
            return rob2

        return max(nums[0], helper(nums[1:]), helper(nums[:-1]))

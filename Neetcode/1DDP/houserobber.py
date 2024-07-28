# https://neetcode.io/problems/house-robber
# https://leetcode.com/problems/house-robber/

from typing import List


class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 1:
            return nums[0]
        nums[1] = max(nums[1], nums[0])
        for i in range(2, n):
            nums[i] = max(nums[i] + nums[i - 2], nums[i - 1])
        return nums[n - 1]

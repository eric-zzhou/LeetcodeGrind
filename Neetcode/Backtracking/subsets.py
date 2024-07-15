# https://neetcode.io/problems/subsets
# https://leetcode.com/problems/subsets/

from typing import List


class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ret = []

        curr = []

        def dfs(ind):
            if ind >= len(nums):
                ret.append(curr.copy())
                return
            curr.append(nums[ind])
            dfs(ind + 1)
            curr.pop()
            dfs(ind + 1)

        dfs(0)
        return ret

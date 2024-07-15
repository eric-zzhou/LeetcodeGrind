# https://neetcode.io/problems/subsets-ii
# https://leetcode.com/problems/subsets-ii/

from typing import List


class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ret = []
        nums.sort()

        curr = []

        def dfs(i):
            if i >= len(nums):
                ret.append(curr[:])
                return
            curr.append(nums[i])
            dfs(i + 1)
            curr.pop()
            ind = i + 1
            while ind < len(nums) and nums[ind] == nums[i]:
                ind += 1
            dfs(ind)

        dfs(0)

        return ret

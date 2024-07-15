# https://neetcode.io/problems/two-integer-sum
# https://leetcode.com/problems/two-sum/
class Solution(object):
    def twoSum(self, nums, target):
        search = {}
        for i, n in enumerate(nums):
            curr = target - n
            if curr in search:
                return search[curr], i
            else:
                search[n] = i

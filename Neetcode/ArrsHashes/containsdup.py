# https://neetcode.io/problems/duplicate-integer
# https://leetcode.com/problems/contains-duplicate/
class Solution(object):
    def containsDuplicate(self, nums):
        exists = set()
        for num in nums:
            if num in exists:
                return True
            else:
                exists.add(num)
        return False

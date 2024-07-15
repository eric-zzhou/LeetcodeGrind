# https://neetcode.io/problems/longest-consecutive-sequence
# https://leetcode.com/problems/longest-consecutive-sequence/

from typing import List


class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0

        nums = sorted(list(set(nums)))
        print(nums)
        longest = 0
        curr = 1
        prev = nums[0]
        for n in nums[1:]:
            if n - prev == 1:
                curr += 1
            else:
                longest = max(curr, longest)
                curr = 1
            prev = n
        return max(curr, longest)

    def longestConsecutive2(self, nums: List[int]) -> int:
        t = set(nums)

        ret = 0
        for n in nums:
            if (n - 1) not in t:
                curr = 1
                while (n + curr) in t:
                    curr += 1
                ret = max(curr, ret)
        return ret

# https://neetcode.io/problems/partition-equal-subset-sum
# https://leetcode.com/problems/partition-equal-subset-sum/

from typing import List


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 == 1:
            return False

        total //= 2

        dp = set()
        dp.add(0)

        for i in range(len(nums)):
            temp = set()
            for v in dp:
                if v + nums[i] == total:
                    return True
                elif v + nums[i] < total:
                    temp.add(v + nums[i])
                temp.add(v)
            dp = temp

        return False

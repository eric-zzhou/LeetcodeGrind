# https://neetcode.io/problems/three-integer-sum
# https://leetcode.com/problems/3sum/

from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ret = []
        nums = sorted(nums)

        for i in range(len(nums) - 2):
            if i > 0 and nums[i] == nums[i - 1]:
                continue

            if nums[i] > 0:
                return ret

            t = -nums[i]
            j, k = i + 1, len(nums) - 1
            while j < k:
                temp = nums[j] + nums[k]
                if temp < t:
                    j += 1
                elif temp > t:
                    k -= 1
                else:
                    ret.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    while nums[j] == nums[j - 1] and j < k:
                        j += 1
        return ret

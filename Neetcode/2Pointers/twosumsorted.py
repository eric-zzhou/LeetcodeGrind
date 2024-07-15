# https://neetcode.io/problems/two-integer-sum-ii
# https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

from typing import List


class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        l, r = 0, len(numbers) - 1
        while l < r:
            curr = numbers[l] + numbers[r]
            if curr < target:
                l += 1
            elif curr > target:
                r -= 1
            else:
                return [l + 1, r + 1]

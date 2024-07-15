# https://neetcode.io/problems/kth-largest-element-in-an-array
# https://leetcode.com/problems/kth-largest-element-in-an-array/

from typing import List, Tuple
import random


class Solution:
    def findKthLargest(nums: List[int], k: int) -> int:
        def findWhere(nums, k) -> Tuple:
            great = []
            e = 0
            less = []
            n = len(nums)
            if n < 3:
                pivot = random.choice(nums)
            else:
                mid = n // 2
                medianlist = sorted([nums[0], nums[mid], nums[-1]])
                pivot = medianlist[1]
            for i in nums:
                if i > pivot:
                    great.append(i)
                elif i == pivot:
                    e += 1
                else:
                    less.append(i)
            g = len(great)
            l = len(less)
            if g >= k:
                return (great, k)
            elif g + e >= k:
                return ([pivot], 1)
            else:
                return (less, k - (g + e))

        def recursivefindK(nums, k):
            if k == len(nums):
                return min(nums)
            elif k == 1:
                return max(nums)
            else:
                new = findWhere(nums, k)
                newList = new[0]
                newk = new[1]
                return recursivefindK(newList, newk)

        return recursivefindK(nums, k)

    # Stupid solution
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort(reverse=True)
        return nums[k - 1]

# https://neetcode.io/problems/products-of-array-discluding-self
# https://leetcode.com/problems/product-of-array-except-self/
from types import List


class Solution(object):
    def productExceptSelf2(self, nums: List[int]) -> List[int]:
        zeros = -1
        prod = 1
        for i, n in enumerate(nums):
            if n == 0:
                if zeros != -1:
                    return [0] * len(nums)
                else:
                    zeros = i
            else:
                prod *= n
        if zeros == -1:
            return [prod // n for n in nums]
        else:
            return [0] * zeros + [prod] + [0] * (len(nums) - zeros - 1)

    def productExceptSelf(self, nums):
        prod = 1
        prod2 = 1
        zeros = 0

        for num in nums:
            prod *= num
            if num:
                prod2 *= num
            else:
                zeros += 1

        for i in range(len(nums)):
            if nums[i]:
                nums[i] = prod / nums[i]
            elif zeros == 1:
                nums[i] = prod2
            else:
                nums[i] = 0
        return nums

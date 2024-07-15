# https://neetcode.io/problems/combination-target-sum
# https://leetcode.com/problems/combination-sum/

from typing import List


class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        dp = [[] for _ in range(target + 1)]

        for n in nums:
            if n <= target:
                dp[n].append([n])
            for i in range(n + 1, target + 1):
                for comb in dp[i - n]:
                    dp[i].append(comb + [n])
        return dp[target]

    # Slower backtracking solution
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        ret = []

        def helper(curr, currsum, ind):
            print(curr, currsum, ret)
            for i, n in enumerate(nums[ind:]):
                currsum += n
                curr.append(n)
                if currsum == target:
                    ret.append(curr.copy())
                elif currsum < target:
                    helper(curr, currsum, i + ind)
                currsum -= n
                curr.pop()
            return

        helper([], 0, 0)
        return ret

# https://neetcode.io/problems/burst-balloons
# https://leetcode.com/problems/burst-balloons

from typing import List


class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        nums = [1] + [n for n in nums if n != 0] + [1]
        n = len(nums)
        # dp[l][r] is the maximum coins obtained from bursting all the balloons between nums[l] and nums[r], inclusive
        dp = [[0] * n for _ in range(n)]

        for off in range(1, n - 1):  # offset of the subproblem
            for l in range(1, n - off):  # left boundary of the subproblem
                r = l + off - 1  # right boundary of the subproblem
                for i in range(
                    l, r + 1
                ):  # i is the last balloon to burst in the current subproblem
                    dp[l][r] = max(
                        dp[l][r],
                        dp[l][i - 1]
                        + nums[l - 1] * nums[i] * nums[r + 1]
                        + dp[i + 1][r],
                    )
        return dp[1][n - 2]


class SlowSolution:
    def maxCoins(self, nums: List[int]) -> int:
        n = len(nums)
        nums = [1] + nums + [1]
        track = {}

        def dfs(l, r):
            if (l, r) in track:
                return track[(l, r)]
            if l == r:
                track[(l, r)] = nums[l - 1] * nums[l] * nums[r + 1]
                return track[(l, r)]

            ret = 0
            for i in range(l, r + 1):
                ret = max(
                    ret,
                    (
                        nums[l - 1] * nums[i] * nums[r + 1]
                        + dfs(l, i - 1)
                        + dfs(i + 1, r)
                    ),
                )

            track[(l, r)] = ret
            return ret

        return dfs(1, n)

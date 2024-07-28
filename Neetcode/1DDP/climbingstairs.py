# https://neetcode.io/problems/climbing-stairs
# https://leetcode.com/problems/climbing-stairs/


class Solution:
    def climbStairs(self, n: int) -> int:
        track = [1] * (n + 1)
        for i in range(2, n + 1):
            track[i] = track[i - 2] + track[i - 1]
        return track[-1]

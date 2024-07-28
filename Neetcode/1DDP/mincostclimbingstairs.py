# https://neetcode.io/problems/min-cost-climbing-stairs
# https://leetcode.com/problems/min-cost-climbing-stairs/

from typing import List


class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        n = len(cost)
        track = [0] * (n + 1)
        for i in range(2, n + 1):
            track[i] = min(track[i - 2] + cost[i - 2], track[i - 1] + cost[i - 1])
        return track[n]

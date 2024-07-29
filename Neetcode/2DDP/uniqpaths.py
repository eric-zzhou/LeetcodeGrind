# https://neetcode.io/problems/count-paths
# https://leetcode.com/problems/unique-paths/


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [1] * n
        for i in range(1, m):
            for j in range(1, n):
                dp[j] += dp[j - 1]
        return dp[-1]


class WorseSolution:
    def uniquePaths(self, m: int, n: int) -> int:
        grid = [([0] * m) for _ in range(n)]
        grid[0][0] = 1
        for i in range(n):
            for j in range(m):
                if i > 0:
                    grid[i][j] += grid[i - 1][j]
                if j > 0:
                    grid[i][j] += grid[i][j - 1]
        return grid[n - 1][m - 1]

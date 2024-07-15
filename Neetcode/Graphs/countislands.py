# https://neetcode.io/problems/count-number-of-islands
# https://leetcode.com/problems/number-of-islands/

from typing import List


class Solution:
    def numIslands(grid: List[List[str]]) -> int:
        row, col = len(grid), len(grid[0])
        ret = 0

        def dfs(r, c, grid):
            grid[r][c] = "0"
            if r < row - 1 and grid[r + 1][c] == "1":
                dfs(r + 1, c, grid)
            if r > 0 and grid[r - 1][c] == "1":
                dfs(r - 1, c, grid)
            if c < col - 1 and grid[r][c + 1] == "1":
                dfs(r, c + 1, grid)
            if c > 0 and grid[r][c - 1] == "1":
                dfs(r, c - 1, grid)

        for r in range(row):
            for c in range(col):
                if grid[r][c] == "1":
                    dfs(r, c, grid)
                    ret += 1
        return ret

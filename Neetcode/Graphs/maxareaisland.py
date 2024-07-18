# https://neetcode.io/problems/max-area-of-island
# https://leetcode.com/problems/max-area-of-island/

from typing import List


class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        HEIGHT = len(grid)
        WIDTH = len(grid[0])

        def dfs(i, j):
            grid[i][j] = 0
            ret = 1
            if i > 0 and grid[i - 1][j]:
                ret += dfs(i - 1, j)
            if i < HEIGHT - 1 and grid[i + 1][j]:
                ret += dfs(i + 1, j)
            if j > 0 and grid[i][j - 1]:
                ret += dfs(i, j - 1)
            if j < WIDTH - 1 and grid[i][j + 1]:
                ret += dfs(i, j + 1)
            return ret

        ret = 0
        for i in range(HEIGHT):
            for j in range(WIDTH):
                if grid[i][j]:
                    res = dfs(i, j)
                    print(i, j, res)
                    ret = max(ret, res)
        return ret

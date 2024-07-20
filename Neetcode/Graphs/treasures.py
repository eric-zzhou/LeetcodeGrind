# https://neetcode.io/problems/islands-and-treasure
# https://leetcode.com/problems/walls-and-gates/ (locked)


from typing import List


class Solution:
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        HEIGHT = len(grid)
        WIDTH = len(grid[0])

        def dfs(i, j, curr):
            grid[i][j] = curr
            if i + 1 < HEIGHT and curr + 1 < grid[i + 1][j]:
                dfs(i + 1, j, curr + 1)
            if i - 1 >= 0 and curr + 1 < grid[i - 1][j]:
                dfs(i - 1, j, curr + 1)
            if j + 1 < WIDTH and curr + 1 < grid[i][j + 1]:
                dfs(i, j + 1, curr + 1)
            if j - 1 >= 0 and curr + 1 < grid[i][j - 1]:
                dfs(i, j - 1, curr + 1)

        for i in range(HEIGHT):
            for j in range(WIDTH):
                if grid[i][j] == 0:
                    dfs(i, j, 0)

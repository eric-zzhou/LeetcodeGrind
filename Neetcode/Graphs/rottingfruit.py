# https://neetcode.io/problems/rotting-fruit
# https://leetcode.com/problems/rotting-oranges/

from typing import List
from collections import deque


class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        ROWS = len(grid)
        COLS = len(grid[0])
        q = deque()
        fresh = 0

        for r in range(ROWS):
            for c in range(COLS):
                if grid[r][c] == 2:
                    q.append((r, c))
                if grid[r][c] == 1:
                    fresh += 1

        time = 0
        directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
        while fresh > 0 and q:
            length = len(q)
            for _ in range(length):
                r, c = q.popleft()

                for dr, dc in directions:
                    row, col = r + dr, c + dc
                    if (
                        row in range(len(grid))
                        and col in range(len(grid[0]))
                        and grid[row][col] == 1
                    ):
                        grid[row][col] = 2
                        q.append((row, col))
                        fresh -= 1
            time += 1
        return time if fresh == 0 else -1


class StupidFloodfillSolution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        HEIGHT = len(grid)
        WIDTH = len(grid[0])
        DONE = WIDTH * HEIGHT

        good = [([DONE] * WIDTH) for _ in range(HEIGHT)]

        def dfs(i, j, curr):
            val = grid[i][j]
            grid[i][j] = 0
            good[i][j] = curr

            if i > 0 and grid[i - 1][j] == 1 and curr < good[i - 1][j] - 1:
                dfs(i - 1, j, curr + 1)
            if i < HEIGHT - 1 and grid[i + 1][j] == 1 and curr < good[i + 1][j] - 1:
                dfs(i + 1, j, curr + 1)
            if j > 0 and grid[i][j - 1] == 1 and curr < good[i][j - 1] - 1:
                dfs(i, j - 1, curr + 1)
            if j < WIDTH - 1 and grid[i][j + 1] == 1 and curr < good[i][j + 1] - 1:
                dfs(i, j + 1, curr + 1)

            grid[i][j] = val

        for i in range(HEIGHT):
            for j in range(WIDTH):
                if grid[i][j] == 2:
                    dfs(i, j, 0)
                elif grid[i][j] == 1 and good[i][j] == DONE:
                    good[i][j] = 2000

        ret = 0
        for row in good:
            for v in row:
                if v == DONE:
                    continue
                elif v == 2000:
                    return -1
                else:
                    ret = max(ret, v)
        return ret

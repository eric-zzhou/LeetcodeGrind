# https://neetcode.io/problems/surrounded-regions
# https://leetcode.com/problems/surrounded-regions/

from typing import List


class Solution:
    def solve(self, board: List[List[str]]) -> None:
        # check if O island ever touches border
        HEIGHT = len(board)
        WIDTH = len(board[0])

        def dfs(i, j):
            if i < 0 or i >= HEIGHT or j < 0 or j >= WIDTH or board[i][j] != "O":
                return
            board[i][j] = "o"
            for x, y in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                dfs(i + x, y + j)

        # Look at all 4 edges
        for i in range(HEIGHT):
            if board[i][0] == "O":
                dfs(i, 0)
            if board[i][WIDTH - 1] == "O":
                dfs(i, WIDTH - 1)

        for j in range(1, WIDTH - 1):
            if board[0][j] == "O":
                dfs(0, j)
            if board[HEIGHT - 1][j] == "O":
                dfs(HEIGHT - 1, j)

        for i in range(HEIGHT):
            for j in range(WIDTH):
                if board[i][j] == "o":
                    board[i][j] = "O"
                else:
                    board[i][j] = "X"

# https://neetcode.io/problems/search-for-word
# https://leetcode.com/problems/word-search/

from typing import List
from collections import defaultdict


class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        word = list(word)
        HEIGHT = len(board)
        WIDTH = len(board[0])

        def dfs(r, c, i):
            # print(r, c, i, board)
            curr = board[r][c]
            if i >= len(word):
                return True
            for nr, nc in [(r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)]:
                board[r][c] = "*"
                if (
                    0 <= nr
                    and 0 <= nc
                    and nr < HEIGHT
                    and nc < WIDTH
                    and board[nr][nc] == word[i]
                ):
                    if dfs(nr, nc, i + 1):
                        return True
                board[r][c] = curr
            return False

        for r, row in enumerate(board):
            for c, val in enumerate(row):
                if val == word[0]:
                    if dfs(r, c, 1):
                        return True
        return False

    # More optimized solution
    def exist(self, board: List[List[str]], word: str) -> bool:
        m = len(board)
        n = len(board[0])
        if len(word) > m * n:
            return False

        counter = defaultdict(int)
        for i in range(m):
            for j in range(n):
                counter[board[i][j]] += 1

        if counter[word[0]] > counter[word[-1]]:
            word = word[::-1]
        for char in word:
            if counter[char] == 0:
                return False
            counter[char] -= 1

        def backtracking(i, j, k):
            res = False
            if (
                0 <= i < len(board)
                and 0 <= j < len(board[0])
                and k < len(word)
                and board[i][j] == word[k]
            ):
                if k == len(word) - 1:
                    return True

                temp = board[i][j]
                board[i][j] = ""
                res = (
                    backtracking(i + 1, j, k + 1)
                    or backtracking(i - 1, j, k + 1)
                    or backtracking(i, j + 1, k + 1)
                    or backtracking(i, j - 1, k + 1)
                )
                board[i][j] = temp
            return res

        for i in range(len(board)):
            for j in range(len(board[0])):
                if backtracking(i, j, 0):
                    return True

        return False

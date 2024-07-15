# https://neetcode.io/problems/n-queens
# https://leetcode.com/problems/n-queens/

from typing import List


class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        ret = []

        ucols = set()
        rdiag = set()
        ldiag = set()

        def dfs(r, board):
            # Edge cases
            if r == n:
                ret.append(["".join(row) for row in board])
                return
            for c in range(n):
                rd = r - c
                ld = r + c
                if c not in ucols and rd not in rdiag and ld not in ldiag:
                    ucols.add(c)
                    rdiag.add(rd)
                    ldiag.add(ld)
                    board[r][c] = "Q"
                    dfs(r + 1, board)
                    ucols.remove(c)
                    rdiag.remove(rd)
                    ldiag.remove(ld)
                    board[r][c] = "."

        dfs(0, [["." for _ in range(n)] for _ in range(n)])
        return ret

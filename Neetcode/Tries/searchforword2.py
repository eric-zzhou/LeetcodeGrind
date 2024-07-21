# https://neetcode.io/problems/search-for-word-ii
# https://leetcode.com/problems/word-search-ii/

from typing import List


class Solution:
    def findWords(self, board: List[List[str]], words: List[str]) -> List[str]:
        ret = []
        ROWS, COLS = len(board), len(board[0])

        # Build trie
        wtree = {}
        for word in words:
            cur = wtree
            for letter in word:
                cur = cur.setdefault(letter, {})
            cur["*"] = word

        def search(i, j, root):
            let = board[i][j]
            cur = root[let]
            word = cur.pop("*", False)
            if word:
                ret.append(word)

            board[i][j] = "*"  # visited
            for di, dj in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                ni, nj = i + di, j + dj
                if (
                    ni >= 0
                    and nj >= 0
                    and ni < ROWS
                    and nj < COLS
                    and board[ni][nj] in cur
                ):
                    search(ni, nj, cur)
            board[i][j] = let

            if not cur:
                root.pop(let)

        for i in range(ROWS):
            for j in range(COLS):
                if board[i][j] in wtree:
                    search(i, j, wtree)

        return ret

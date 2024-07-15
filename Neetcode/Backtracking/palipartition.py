# https://neetcode.io/problems/palindrome-partitioning
# https://leetcode.com/problems/palindrome-partitioning/

from typing import List


class Solution:
    def isPali(self, s, l, r):
        while l < r:
            if s[l] != s[r]:
                return False
            l += 1
            r -= 1
        return True

    def partition(self, s: str) -> List[List[str]]:
        ret = []
        curr = []

        def dfs(i):
            if i >= len(s):
                ret.append(curr[:])
                return
            for r in range(i, len(s)):
                if self.isPali(s, i, r):
                    curr.append(s[i : r + 1])
                    dfs(r + 1)
                    curr.pop()

        dfs(0)
        return ret

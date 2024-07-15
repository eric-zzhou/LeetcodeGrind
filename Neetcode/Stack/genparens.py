# https://neetcode.io/problems/generate-parentheses
# https://leetcode.com/problems/generate-parentheses/

from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        stack = []
        ret = []

        def helper(l, r):
            if l == r == n:
                ret.append("".join(stack))
                return

            if l < n:
                stack.append("(")
                helper(l + 1, r)
                stack.pop()
            if r < l:
                stack.append(")")
                helper(l, r + 1)
                stack.pop()

        helper(0, 0)
        return ret

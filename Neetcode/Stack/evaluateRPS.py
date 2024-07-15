# https://neetcode.io/problems/evaluate-reverse-polish-notation
# https://leetcode.com/problems/evaluate-reverse-polish-notation/

from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        ops = {
            "+": lambda x, y: x + y,
            "-": lambda x, y: x - y,
            "*": lambda x, y: x * y,
            "/": lambda x, y: int(x / y),
        }
        st = []
        for t in tokens:
            if t not in ops:
                st.append(int(t))
            else:
                y = st.pop()
                x = st.pop()
                st.append(ops[t](x, y))
        return st[0]

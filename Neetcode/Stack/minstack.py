# https://neetcode.io/problems/minimum-stack
# https://leetcode.com/problems/min-stack/


class MinStack:

    def __init__(self):
        self.mn = []
        self.stack = []

    def push(self, val: int) -> None:
        self.stack.append(val)
        if self.mn:
            val = min(val, self.mn[-1])
        self.mn.append(val)

    def pop(self) -> None:
        self.stack.pop()
        self.mn.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.mn[-1]

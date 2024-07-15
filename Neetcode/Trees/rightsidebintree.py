# https://neetcode.io/problems/binary-tree-right-side-view
# https://leetcode.com/problems/binary-tree-right-side-view/

from typing import List, Optional
from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def bfs(self, root: Optional[TreeNode]) -> List[List[int]]:
        if not root:
            return []
        ret = []
        dq = deque()
        dq.append(root)
        while dq:
            temp = []
            for _ in range(len(dq)):
                curr = dq.popleft()
                temp.append(curr.val)
                if curr.left:
                    dq.append(curr.left)
                if curr.right:
                    dq.append(curr.right)
            ret.append(temp)
        return ret

    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        ret = []
        layers = self.bfs(root)
        for layer in layers:
            ret.append(layer[-1])
        return ret

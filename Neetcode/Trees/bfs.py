# https://neetcode.io/problems/level-order-traversal-of-binary-tree
# https://leetcode.com/problems/binary-tree-level-order-traversal/

from typing import List, Optional
from collections import deque


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
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

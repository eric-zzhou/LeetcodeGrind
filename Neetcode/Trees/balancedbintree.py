# https://neetcode.io/problems/balanced-binary-tree
# https://leetcode.com/problems/balanced-binary-tree/

from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def helper(self, root):
        if not root:
            return (True, 0)
        lr, lh = self.helper(root.left)
        rr, rh = self.helper(root.right)
        return ((abs(lh - rh) <= 1) and lr and rr, max(lh, rh) + 1)

    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.helper(root)[0]

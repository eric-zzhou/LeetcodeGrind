# https://neetcode.io/problems/binary-tree-diameter
# https://leetcode.com/problems/diameter-of-binary-tree/

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
            return (0, 0)
        h1, r1 = self.helper(root.left)
        h2, r2 = self.helper(root.right)
        return (max(h1, h2) + 1, max(h1 + h2, r1, r2))

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        return self.helper(root)[1]

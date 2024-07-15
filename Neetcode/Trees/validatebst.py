# https://neetcode.io/problems/valid-binary-search-tree
# https://leetcode.com/problems/validate-binary-search-tree/

from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool:
        # send a range through recursively lol
        def helper(root, l, r):
            if not root:
                return True
            curr = root.val
            if not (l < curr < r):
                return False
            return helper(root.left, l, min(r, curr)) and helper(
                root.right, max(l, curr), r
            )

        return helper(root, float("-inf"), float("inf"))

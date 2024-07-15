# https://neetcode.io/problems/binary-tree-from-preorder-and-inorder-traversal
# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/


from typing import List, Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder:
            return None
        elif len(preorder) == 1:
            return TreeNode(preorder[0])
        root = TreeNode(preorder[0])
        loc = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1 : 1 + loc], inorder[:loc])
        root.right = self.buildTree(preorder[1 + loc :], inorder[loc + 1 :])
        return root

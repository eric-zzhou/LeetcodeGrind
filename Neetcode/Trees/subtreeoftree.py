# https://neetcode.io/problems/subtree-of-a-binary-tree
# https://leetcode.com/problems/subtree-of-another-tree/


from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def equal(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if (p and not q) or (q and not p):
            return False
        elif not p and not q:
            return True

        if p.val != q.val:
            return False

        return self.equal(p.left, q.left) and self.equal(p.right, q.right)

    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        if not subRoot:
            return True
        if not root:
            return False

        if root.val == subRoot.val:
            if self.equal(root.left, subRoot.left) and self.equal(
                root.right, subRoot.right
            ):
                return True

        return self.isSubtree(root.left, subRoot) or self.isSubtree(root.right, subRoot)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSubtree(self, root: Optional[TreeNode], subRoot: Optional[TreeNode]) -> bool:
        def serialize(node):
            global serialized_tree
            if not node:
                tree.append("#")
                return
            tree.append(f"^{node.val}")
            serialize(node.left)
            serialize(node.right)

        tree = []
        serialize(root)
        serialized_root = "".join(tree)
        tree = []
        serialize(subRoot)
        serialized_sub = "".join(tree)
        return serialized_sub in serialized_root

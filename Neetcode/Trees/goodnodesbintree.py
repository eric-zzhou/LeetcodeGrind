# https://neetcode.io/problems/count-good-nodes-in-binary-tree
# https://leetcode.com/problems/count-good-nodes-in-binary-tree/


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def helper(self, root, maxsofar):
        if not root:
            return 0

        tp = 0
        if maxsofar <= root.val:
            tp = 1
            maxsofar = root.val
        return tp + self.helper(root.left, maxsofar) + self.helper(root.right, maxsofar)

    def goodNodes(self, root: TreeNode) -> int:
        return self.helper(root, float("-infinity"))

# https://neetcode.io/problems/kth-smallest-integer-in-bst
# https://leetcode.com/problems/kth-smallest-element-in-a-bst/

from typing import Optional


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        curr = root
        past = []

        while True:
            while curr:
                past.append(curr)
                curr = curr.left
            curr = past.pop()
            k -= 1
            if k == 0:
                return curr.val
            curr = curr.right

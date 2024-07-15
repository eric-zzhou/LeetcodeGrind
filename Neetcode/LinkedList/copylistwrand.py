# https://neetcode.io/problems/copy-linked-list-with-random-pointer
# https://leetcode.com/problems/copy-list-with-random-pointer/

from typing import Optional


class Node:
    def __init__(self, x: int, next: "Node" = None, random: "Node" = None):
        self.val = int(x)
        self.next = next
        self.random = random


class Solution:
    def copyRandomList(self, head: "Optional[Node]") -> "Optional[Node]":
        if not head:
            return None

        hm = {}
        curr = head
        while curr:
            hm[curr] = Node(curr.val)
            curr = curr.next

        curr = head
        while curr:
            ccurr = hm[curr]
            ccurr.next = hm.get(curr.next)
            ccurr.random = hm.get(curr.random)
            curr = curr.next
        return hm[head]

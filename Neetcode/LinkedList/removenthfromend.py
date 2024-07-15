# https://neetcode.io/problems/remove-node-from-end-of-linked-list
# https://leetcode.com/problems/remove-nth-node-from-end-of-list/


from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        l = r = head
        for _ in range(n):
            r = r.next

        if not r:
            return head.next

        while r.next:
            l, r = l.next, r.next

        l.next = l.next.next
        return head

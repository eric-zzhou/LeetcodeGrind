# https://neetcode.io/problems/reorder-linked-list
# https://leetcode.com/problems/reorder-list/

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reorderList(self, head: Optional[ListNode]) -> None:
        # Put slow halfway
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        if fast:
            slow = slow.next

        # Reverse second half
        prev = None
        while slow:
            temp = slow.next
            slow.next = prev
            prev = slow
            slow = temp

        # Combine
        begin, end = head, prev
        while end:
            temp = end.next
            end.next = begin.next
            begin.next = end
            end = temp
            begin = begin.next.next
        begin.next = None

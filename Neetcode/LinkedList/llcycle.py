# https://neetcode.io/problems/linked-list-cycle-detection
# https://leetcode.com/problems/linked-list-cycle/

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        fast = head
        while fast and fast.next:
            fast = fast.next.next
            head = head.next
            if fast == head:
                return True
        return False

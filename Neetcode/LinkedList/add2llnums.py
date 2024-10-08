# https://neetcode.io/problems/add-two-numbers
# https://leetcode.com/problems/add-two-numbers/

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def addTwoNumbers(
        self, l1: Optional[ListNode], l2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = prev = ListNode()
        carry = 0
        while l1 or l2 or carry:
            f = l1.val if l1 else 0
            s = l2.val if l2 else 0
            value = f + s + carry
            carry = value // 10
            value = value % 10
            prev.next = ListNode(value)
            prev = prev.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None

        return dummy.next

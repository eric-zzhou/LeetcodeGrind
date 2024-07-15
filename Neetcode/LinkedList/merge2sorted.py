# https://neetcode.io/problems/merge-two-sorted-linked-lists
# https://leetcode.com/problems/merge-two-sorted-lists/

from typing import Optional


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution(object):
    def mergeTwoLists(
        self, list1: Optional[ListNode], list2: Optional[ListNode]
    ) -> Optional[ListNode]:
        dummy = prev = ListNode()

        while list1 and list2:
            if list2.val < list1.val:
                prev.next = list2
                list2 = list2.next
            else:
                prev.next = list1
                list1 = list1.next
            prev = prev.next

        if list1:
            prev.next = list1
        else:
            prev.next = list2

        return dummy.next

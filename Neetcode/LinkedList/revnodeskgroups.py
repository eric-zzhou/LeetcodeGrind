# https://neetcode.io/problems/reverse-nodes-in-k-group
# https://leetcode.com/problems/reverse-nodes-in-k-group/

from typing import Optional


# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        dummy = ListNode(0, head)
        groupPrev = dummy

        while True:
            kth = self.getKth(groupPrev, k)
            if not kth:
                break
            groupNext = kth.next

            prev, curr = kth.next, groupPrev.next
            while curr != groupNext:
                tmp = curr.next
                curr.next = prev
                prev = curr
                curr = tmp

            tmp = groupPrev.next
            groupPrev.next = kth
            groupPrev = tmp
        return dummy.next

    def getKth(self, curr, k):
        while curr and k > 0:
            curr = curr.next
            k -= 1
        return curr


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next


class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        l = r = head
        for _ in range(k - 1):
            if r:
                r = r.next
            else:
                return head

        head = r
        while r:
            # Reverse group
            prev = None
            curr = l
            for _ in range(k):
                temp = curr.next
                curr.next = prev
                prev = curr
                curr = temp
                r = r.next if r else None
            l.next = r if r else curr
            l = curr

        return head

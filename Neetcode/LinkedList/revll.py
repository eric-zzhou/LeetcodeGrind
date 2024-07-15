# https://neetcode.io/problems/reverse-a-linked-list
# https://leetcode.com/problems/reverse-linked-list/


class Solution(object):
    def reverseList(self, head):
        prev = None
        while head is not None:
            curr = head
            head = head.next
            curr.next = prev
            prev = curr
        return prev

    def reverseList(self, head):
        prev, current = None, head
        while current:
            current.next, prev, current = prev, current, current.next
        return prev

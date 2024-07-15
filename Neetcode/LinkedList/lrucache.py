# https://neetcode.io/problems/lru-cache
# https://leetcode.com/problems/lru-cache/

from collections import OrderedDict


class LRUCache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.linkedList = OrderedDict()

    def put(self, key, value):
        if key in self.linkedList:
            self.linkedList.move_to_end(key)
        else:
            if len(self.linkedList) == self.capacity:
                self.linkedList.popitem(last=False)
        self.linkedList[key] = value

    def get(self, key):
        if key not in self.linkedList:
            return -1

        self.linkedList.move_to_end(key)
        return self.linkedList[key]


class Node:
    def __init__(self, key, value):
        self.key, self.val = key, value
        self.next = self.prev = None


class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.size = 0
        self.hm = {}  # key -> node

        self.left, self.right = Node(0, 0), Node(0, 0)
        self.left.next, self.right.prev = self.right, self.left

    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev

    def prepend(self, node):
        left, nxt = self.left, self.left.next
        node.prev, node.next = left, nxt
        left.next = nxt.prev = node

    def get(self, key: int) -> int:
        if key in self.hm:
            self.remove(self.hm[key])
            self.prepend(self.hm[key])
            return self.hm[key].val
        return -1

    # def print_lst(self):
    #     curr = self.left
    #     while curr:
    #         print(f"({curr.key}, {curr.val})", end=", ")
    #         curr = curr.next
    #     print()

    def put(self, key: int, value: int) -> None:
        if key in self.hm:
            self.remove(self.hm[key])
        elif self.size < self.cap:
            self.size += 1
        else:
            lru = self.right.prev
            # self.print_lst()
            self.remove(lru)
            # self.print_lst()
            del self.hm[lru.key]
        self.hm[key] = Node(key, value)
        self.prepend(self.hm[key])
        # print(self.hm)

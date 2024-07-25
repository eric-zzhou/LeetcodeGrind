# https://neetcode.io/problems/course-schedule-ii
# https://leetcode.com/problems/course-schedule-ii/


from typing import List
from json import loads
from sys import stdin
from collections import deque


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        indeg = [0] * numCourses
        children = [[] for _ in range(numCourses)]
        for a, b in prerequisites:
            indeg[a] += 1
            children[b].append(a)

        q = deque()
        ret = []

        for i in range(numCourses):
            if indeg[i] == 0:
                q.append(i)

        while q:
            curr = q.popleft()
            ret.append(curr)
            for child in children[curr]:
                indeg[child] -= 1
                if indeg[child] == 0:
                    q.append(child)
        return [] if len(ret) != numCourses else ret


with open("user.out", "w") as f:
    inputs = map(loads, stdin)
    for nums in inputs:
        print(str(Solution().findOrder(nums, next(inputs))).replace(" ", ""), file=f)
exit(0)

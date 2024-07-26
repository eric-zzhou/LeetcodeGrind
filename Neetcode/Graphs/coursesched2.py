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


class StupidSolution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        prereq = {c: [] for c in range(numCourses)}
        for crs, pre in prerequisites:
            prereq[crs].append(pre)

        output = []
        visit, cycle = set(), set()

        def dfs(crs):
            if crs in cycle:
                return False
            if crs in visit:
                return True

            cycle.add(crs)
            for pre in prereq[crs]:
                if dfs(pre) == False:
                    return False
            cycle.remove(crs)
            visit.add(crs)
            output.append(crs)
            return True

        for c in range(numCourses):
            if dfs(c) == False:
                return []
        return output


with open("user.out", "w") as f:
    inputs = map(loads, stdin)
    for nums in inputs:
        print(str(Solution().findOrder(nums, next(inputs))).replace(" ", ""), file=f)
exit(0)

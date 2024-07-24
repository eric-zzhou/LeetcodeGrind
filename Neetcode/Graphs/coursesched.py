# https://neetcode.io/problems/course-schedule
# https://leetcode.com/problems/course-schedule/

from typing import List


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        track = [[] for _ in range(numCourses)]
        for a, b in prerequisites:
            track[a].append(b)

        visited = set()

        def dfs(i):
            if i in visited:
                return False

            visited.add(i)
            for pre in track[i]:
                if not dfs(pre):
                    return False
            visited.remove(i)
            track[i] = []  # key optimization
            return True

        for i in range(numCourses):
            if not dfs(i):
                return False
        return True


# def solve():
#     f = open("user.out", "w")
#     iterator = map(loads, stdin)
#     while True:
#         try:
#             n = next(iterator)
#             preq = next(iterator)
#         except StopIteration:
#             break
#         print(solution.canFinish(n, preq), file=f)


# solution = Solution()
# solve()
# exit()

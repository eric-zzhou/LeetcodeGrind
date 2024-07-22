# https://neetcode.io/problems/pacific-atlantic-water-flow
# https://leetcode.com/problems/pacific-atlantic-water-flow/

from typing import List


class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        HEIGHT = len(heights)
        WIDTH = len(heights[0])

        def dfs(curr, visit, i, j):
            if (
                (i, j) in visit
                or i < 0
                or i >= HEIGHT
                or j < 0
                or j >= WIDTH
                or heights[i][j] < curr
            ):
                return

            visit.add((i, j))
            for x, y in [[1, 0], [-1, 0], [0, 1], [0, -1]]:
                dfs(heights[i][j], visit, i + x, y + j)

        pac = set()
        atl = set()
        for i in range(HEIGHT):
            dfs(0, pac, i, 0)
            dfs(0, atl, i, WIDTH - 1)

        for j in range(WIDTH):
            dfs(0, pac, 0, j)
            dfs(0, atl, HEIGHT - 1, j)

        ret = []
        for i in range(HEIGHT):
            for j in range(WIDTH):
                if (i, j) in pac and (i, j) in atl:
                    ret.append([i, j])

        return ret


# it = iter(stdin)
# output = open("user.out", "w")
# for array in it:
#     output.write(
#         dumps(Solution.pacificAtlantic(Self, loads(array))).replace(" ", "") + "\n"
#     )
# exit()

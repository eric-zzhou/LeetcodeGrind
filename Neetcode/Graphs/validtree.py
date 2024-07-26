# https://neetcode.io/problems/valid-tree
# https://leetcode.com/problems/graph-valid-tree/
# https://www.lintcode.com/problem/178/

from typing import List


class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if not n:
            return True

        adj = {i: [] for i in range(n)}
        for a, b in edges:
            adj[a].append(b)
            adj[b].append(a)

        visited = set()

        def dfs(i, prev):
            if i in visited:
                return False

            visited.add(i)
            for ne in adj[i]:
                if ne == prev:
                    continue
                if not dfs(ne, i):
                    return False
            return True

        return dfs(0, -1) and n == len(visited)

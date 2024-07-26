# https://neetcode.io/problems/count-connected-components
# https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/

from typing import List


class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        par = [i for i in range(n)]
        sizes = [1] * n

        def find(i):
            curr = i
            while curr != par[curr]:
                par[curr] = par[par[curr]]
                curr = par[curr]
            return curr

        def union(a, b):
            a, b = find(a), find(b)
            if a == b:
                return 0

            if sizes[b] > sizes[a]:
                par[a] = b
                sizes[b] += sizes[a]
            else:
                par[b] = a
                sizes[a] += sizes[b]
            return 1

        ret = n
        for a, b in edges:
            ret -= union(a, b)
        return ret


class DFSSolution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        visited = set()
        connections = [[] for _ in range(n)]

        for a, b in edges:
            connections[a].append(b)
            connections[b].append(a)

        def dfs(i):
            visited.add(i)
            for c in connections[i]:
                if c not in visited:
                    dfs(c)

        ret = 0
        for i in range(n):
            if i not in visited:
                ret += 1
                dfs(i)
        return ret

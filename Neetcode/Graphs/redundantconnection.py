# https://neetcode.io/problems/redundant-connection
# https://leetcode.com/problems/redundant-connection/

from typing import List


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        pars = [i for i in range(n)]
        ranks = [1] * n

        def find(a):
            while a != pars[a]:
                pars[a] = pars[pars[a]]
                a = pars[a]
            return a

        def union(a, b):
            a = find(a)
            b = find(b)

            if pars[a] == pars[b]:
                return True

            if ranks[b] > ranks[a]:
                pars[a] = b
                ranks[b] += ranks[a]
            else:
                pars[b] = a
                ranks[a] += ranks[b]
            return False

        for a, b in edges:
            if union(a - 1, b - 1):
                return [a, b]

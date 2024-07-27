# https://neetcode.io/problems/word-ladder
# https://leetcode.com/problems/word-ladder/

from collections import deque, defaultdict
from typing import List


class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0

        m = len(beginWord)
        graph = defaultdict(list)

        for word in wordList:
            for j in range(m):
                graph[word[:j] + "*" + word[j + 1 :]].append(word)

        dq = deque([beginWord])
        visited = set([beginWord])
        ret = 1
        while dq:
            n = len(dq)
            for _ in range(n):
                curr = dq.popleft()
                if curr == endWord:
                    return ret
                for j in range(m):
                    for ne in graph[curr[:j] + "*" + curr[j + 1 :]]:
                        if ne not in visited:
                            dq.append(ne)
                            visited.add(ne)
            ret += 1
        return 0


class DumbestSolution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        m = len(beginWord)
        poss = False
        graph = defaultdict(list)

        # Check if only single letter diff
        def singlediff(a, b):
            diff = False
            for k in range(m):
                if a[k] != b[k]:
                    if diff:
                        return False
                    diff = True
            return True

        # Build graph
        for i, a in enumerate(wordList):
            if wordList[i] == endWord:
                poss = True
            for b in wordList[i + 1 :]:
                if singlediff(a, b):
                    graph[a].append(b)
                    graph[b].append(a)
            if singlediff(beginWord, a):
                graph[beginWord].append(a)

        # End word in list
        if not poss:
            return 0

        # BFS
        dq = deque([beginWord])
        visited = set([beginWord])
        ret = 1
        while dq:
            n = len(dq)
            for _ in range(n):
                curr = dq.popleft()
                if curr == endWord:
                    return ret
                for ne in graph[curr]:
                    if ne not in visited:
                        visited.add(ne)
                        dq.append(ne)
            ret += 1
        return 0

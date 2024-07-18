# https://neetcode.io/problems/clone-graph
# https://leetcode.com/problems/clone-graph/


from typing import Optional
from collections import deque


class Node:
    """
    # Definition for a Node.
    """

    def __init__(self, val=0, neighbors=None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []


class BestSolution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        if not node:
            return None

        track = {}
        track[node] = Node(node.val)
        dq = deque([node])

        while dq:
            current_node = dq.popleft()
            for neighbor in current_node.neighbors:
                if neighbor not in track:
                    track[neighbor] = Node(neighbor.val)
                    dq.append(neighbor)
                track[current_node].neighbors.append(track[neighbor])
        return track[node]


class BetterSolution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        if not node:
            return None

        track = {}

        def dfs(n):
            if n in track:
                return track[n]

            clone = Node(n.val)
            track[n] = clone
            for ne in n.neighbors:
                clone.neighbors.append(dfs(ne))
            return clone

        return dfs(node)


class StupidSolution:
    def cloneGraph(self, node: Optional["Node"]) -> Optional["Node"]:
        if not node:
            return None

        track = {}

        def dfs(n):
            track[n] = Node(n.val, [ne for ne in n.neighbors])
            for ne in n.neighbors:
                if ne not in track:
                    dfs(ne)

        dfs(node)
        for n in track.values():
            for i in range(len(n.neighbors)):
                n.neighbors[i] = track[n.neighbors[i]]
        return track[node]

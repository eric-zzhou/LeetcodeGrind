# https://neetcode.io/problems/k-closest-points-to-origin
# https://leetcode.com/problems/k-closest-points-to-origin/

from typing import List


class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:
        points.sort(key=self.distance)
        return points[:k]

    def distance(self, point):
        return point[0] ** 2 + point[1] ** 2

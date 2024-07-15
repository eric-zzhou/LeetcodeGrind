# https://neetcode.io/problems/search-2d-matrix
# https://leetcode.com/problems/search-a-2d-matrix/

from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        m, n = len(matrix), len(matrix[0])
        l, r = 0, m * n - 1
        while l <= r:
            mid = l + (r - l) // 2
            ro, c = mid // n, mid % n
            curr = matrix[ro][c]
            if target == curr:
                return True
            elif target < curr:
                r = ro * n + c - 1
            else:  # target > curr
                l = ro * n + c + 1
        return False

    # def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
    #     for row in matrix:
    #         if target in row:
    #             return True
    #     return False

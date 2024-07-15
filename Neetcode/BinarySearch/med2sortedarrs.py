# https://neetcode.io/problems/median-of-two-sorted-arrays
# https://leetcode.com/problems/median-of-two-sorted-arrays/

from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        n1, n2 = len(nums1), len(nums2)
        if n2 < n1:  # n1 is always smaller
            (
                nums1,
                nums2,
            ) = (
                nums2,
                nums1,
            )
            n1, n2 = n2, n1
        total = n1 + n2
        half, odd = total // 2, total % 2

        l, r = 0, n1 - 1
        while True:
            i = l + (r - l) // 2
            j = half - i - 2
            l1 = nums1[i] if i >= 0 else float("-infinity")
            r1 = nums1[i + 1] if (i + 1) < n1 else float("infinity")
            l2 = nums2[j] if j >= 0 else float("-infinity")
            r2 = nums2[j + 1] if (j + 1) < n2 else float("infinity")

            if l1 <= r2 and l2 <= r1:
                if odd:
                    return min(r1, r2)
                return (max(l1, l2) + min(r1, r2)) / 2
            elif l1 > r2:
                r = i - 1
            else:  # l2 > r1
                l = i + 1

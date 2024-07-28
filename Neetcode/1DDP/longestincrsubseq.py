# https://neetcode.io/problems/longest-increasing-subsequence
# https://leetcode.com/problems/longest-increasing-subsequence/

from typing import List
from bisect import bisect_left


class Solution:  # 68 ms, faster than 93.92%
    def lengthOfLIS(self, nums: List[int]) -> int:
        sub = []
        for x in nums:
            if len(sub) == 0 or sub[-1] < x:
                sub.append(x)
            else:
                idx = bisect_left(sub, x)  # Find the index of the first element >= x
                sub[idx] = x  # Replace that number with x
        return len(sub)


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        track = [-1001] * (len(nums) + 1)
        latest = 0

        for n in nums:
            if n > track[latest]:
                latest += 1
                track[latest] = n
            else:
                temp = latest
                while temp > 0 and n <= track[temp]:
                    temp -= 1
                track[temp + 1] = min(track[temp + 1], n)
        print(track)
        return latest

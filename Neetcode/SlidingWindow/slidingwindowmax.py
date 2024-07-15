# https://neetcode.io/problems/sliding-window-maximum
# https://leetcode.com/problems/sliding-window-maximum/

from typing import List
from collections import deque


class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        ret = []
        track = deque()

        for r in range(k):
            while track and nums[r] > track[-1]:
                track.pop()
            track.append(nums[r])

        ret.append(track[0])
        for l in range(1, len(nums) - k + 1):
            if nums[l - 1] == track[0]:
                track.popleft()
            new = nums[l + k - 1]
            while track and new > track[-1]:
                track.pop()
            track.append(new)

            ret.append(track[0])

        return ret

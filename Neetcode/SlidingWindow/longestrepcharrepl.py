# https://neetcode.io/problems/longest-repeating-substring-with-replacement
# https://leetcode.com/problems/longest-repeating-character-replacement/

from typing import List


class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        maxf = 0
        track = {}
        l = 0

        for r in range(len(s)):
            curr = s[r]
            t = track.get(curr, 0) + 1
            maxf = max(maxf, t)
            track[curr] = t

            if r - l + 1 - maxf > k:
                track[s[l]] -= 1
                l += 1

        return r - l + 1

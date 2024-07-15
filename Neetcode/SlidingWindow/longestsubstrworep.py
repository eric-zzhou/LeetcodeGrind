# https://neetcode.io/problems/longest-substring-without-duplicates
# https://leetcode.com/problems/longest-substring-without-repeating-characters/

from typing import List


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        ret = 0
        l = 0
        track = set()

        for r, c in enumerate(s):
            if c in track:
                ret = max(ret, r - l)
                while c in track:
                    track.remove(s[l])
                    l += 1
            track.add(c)
        return max(ret, len(track))

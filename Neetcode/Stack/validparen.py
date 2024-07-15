# https://neetcode.io/problems/validate-parentheses
# https://leetcode.com/problems/valid-parentheses/

from typing import List


class Solution:
    def isValid(self, s: str) -> bool:
        d = {"[": "]", "{": "}", "(": ")"}
        track = []
        for c in s:
            if c in d:
                track.append(d[c])
            else:
                if len(track) == 0:
                    return False
                if c != track.pop():
                    return False
        if len(track) != 0:
            return False
        return True

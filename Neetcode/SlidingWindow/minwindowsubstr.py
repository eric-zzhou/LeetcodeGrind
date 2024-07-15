# https://neetcode.io/problems/minimum-window-with-characters
# https://leetcode.com/problems/minimum-window-substring/

from typing import List


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        key = {}
        track = {}
        for c in t:
            key[c] = key.get(c, 0) + 1
            track[c] = 0

        have, need = 0, len(key)
        ret, mini = (-1, -1), 100001
        l = 0
        for r in range(len(s)):
            c = s[r]

            if c in track:
                track[c] += 1
                if track[c] == key[c]:
                    have += 1

            while have == need:
                leng = r - l + 1
                if leng < mini:
                    ret = (l, r)
                    mini = r - l + 1

                if s[l] in track:
                    track[s[l]] -= 1
                    if track[s[l]] < key[s[l]]:
                        have -= 1
                l += 1
            # print(r, track, have, need, ret)

        l, r = ret
        print(l, r)
        return s[l : r + 1] if mini != 100001 else ""

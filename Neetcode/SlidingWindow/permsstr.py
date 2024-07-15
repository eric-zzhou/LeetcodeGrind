# https://neetcode.io/problems/permutation-string
# https://leetcode.com/problems/permutation-in-string/


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        key = {}
        for c in s1:
            key[c] = key.get(c, 0) + 1

        n = len(s1)
        track = {}
        for c in s2[0:n]:
            track[c] = track.get(c, 0) + 1

        for i in range(n, len(s2)):
            if track == key:
                return True
            if track[s2[i - n]] == 1:
                del track[s2[i - n]]
            else:
                track[s2[i - n]] -= 1
            track[s2[i]] = track.get(s2[i], 0) + 1

        return track == key

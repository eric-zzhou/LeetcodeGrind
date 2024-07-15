# https://neetcode.io/problems/is-anagram
# https://leetcode.com/problems/valid-anagram/submissions/1072995158/


class Solution(object):
    def isAnagram(self, s, t):
        track = {}
        for l in s:
            if l not in track:
                track[l] = 1
            else:
                track[l] += 1
        for l in t:
            if l not in track:
                return False
            else:
                track[l] -= 1
        for val in track.values():
            if val:
                return False
        return True

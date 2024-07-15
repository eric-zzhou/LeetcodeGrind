# https://neetcode.io/problems/anagram-groups
# https://leetcode.com/problems/group-anagrams/
from collections import defaultdict
from types import List


class Solution:
    def strset(self, s):
        t = [0] * 26
        for c in s:
            t[ord(c) - ord("a")] += 1
        return tuple(t)

    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ret = defaultdict(list)
        for s in strs:
            t = self.strset(s)
            ret[t].append(s)
        return ret.values()

# https://neetcode.io/problems/palindromic-substrings
# https://leetcode.com/problems/palindromic-substrings/


class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        ret = 0

        for i in range(n):
            l = r = i
            while l >= 0 and r < n and s[l] == s[r]:
                ret += 1
                l -= 1
                r += 1

            l = i
            r = i + 1
            while l >= 0 and r < n and s[l] == s[r]:
                ret += 1
                l -= 1
                r += 1

        return ret

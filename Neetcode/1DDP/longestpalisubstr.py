# https://neetcode.io/problems/longest-palindromic-substring
# https://leetcode.com/problems/longest-palindromic-substring/


class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        ret = ""
        mlen = 0

        for i in range(n):
            l = r = i
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 > mlen:
                    mlen = r - l + 1
                    ret = s[l : r + 1]

                l -= 1
                r += 1

            l = i
            r = i + 1
            while l >= 0 and r < n and s[l] == s[r]:
                if r - l + 1 > mlen:
                    mlen = r - l + 1
                    ret = s[l : r + 1]

                l -= 1
                r += 1

        return ret

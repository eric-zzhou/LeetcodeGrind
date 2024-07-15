# https://neetcode.io/problems/is-palindrome
# https://leetcode.com/problems/valid-palindrome/
class Solution(object):
    def isPalindrome(self, s):
        if len(s) <= 1:
            return True
        p1, p2, s = 0, len(s) - 1, s.lower()
        while p2 > p1:
            while not s[p2].isalnum():
                if p2 <= p1:
                    return True
                p2 -= 1
            while not s[p1].isalnum():
                if p1 >= p2:
                    return True
                p1 += 1
            if s[p1] != s[p2]:
                return False
            p1 += 1
            p2 -= 1
        return True

    def isPalindrome2(self, s: str) -> bool:
        if len(s) <= 1:
            return True
        s = "".join(filter(str.isalnum, s))
        s = s.lower()

        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

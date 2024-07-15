# https://neetcode.io/problems/combinations-of-a-phone-number
# https://leetcode.com/problems/letter-combinations-of-a-phone-number/

from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:

        res = []
        d = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz",
        }

        def backtrack(curr, currStr):
            if len(currStr) == len(digits):
                res.append(currStr)
                return
            for c in d[digits[curr]]:
                backtrack(curr + 1, currStr + c)
            return

        if digits:
            backtrack(0, "")
        return res

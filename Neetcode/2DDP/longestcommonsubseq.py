# https://neetcode.io/problems/longest-common-subsequence
# https://leetcode.com/problems/longest-common-subsequence/


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n, m = len(text1), len(text2)
        track = [([0] * (m + 1)) for _ in range(n + 1)]

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if text1[i - 1] == text2[j - 1]:
                    track[i][j] = 1 + track[i - 1][j - 1]
                else:
                    track[i][j] = max(track[i - 1][j], track[i][j - 1])
        return track[n][m]

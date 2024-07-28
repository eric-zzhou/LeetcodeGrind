# https://neetcode.io/problems/decode-ways
# https://leetcode.com/problems/decode-ways/


# Slightly cleaner solution
class Solution:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0

        dp = [0] * (len(s) + 1)
        dp[0] = dp[1] = 1

        for i in range(1, len(s)):
            if s[i] == "0":
                if s[i - 1] == "1" or s[i - 1] == "2":
                    dp[i + 1] = dp[i - 1]
                else:
                    return 0
            else:
                if 10 < int(s[i - 1 : i + 1]) <= 26:
                    dp[i + 1] = dp[i] + dp[i - 1]
                else:
                    dp[i + 1] = dp[i]

        return dp[-1]


class MySolution:
    def numDecodings(self, s: str) -> int:
        if s[0] == "0":
            return 0

        n = len(s)
        track = [0] * (n + 1)
        track[0] = track[1] = 1
        prev = int(s[0])
        for i in range(2, n + 1):
            curr = int(s[i - 1])
            if curr == 0 and prev == 0:
                return 0

            if curr != 0:
                track[i] = track[i - 1]
            if prev != 0 and 10 * prev + curr <= 26:
                track[i] += track[i - 2]
            prev = curr
        print(track)
        return track[n]

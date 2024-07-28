# https://neetcode.io/problems/coin-change
# https://leetcode.com/problems/coin-change/

from typing import List


class olution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        track = [99999] * (amount + 1)
        track[0] = 0

        for i in range(amount + 1):
            for c in coins:
                if i + c < amount + 1:
                    track[i + c] = min(track[i] + 1, track[i + c])
        return track[amount] if track[amount] != 99999 else -1

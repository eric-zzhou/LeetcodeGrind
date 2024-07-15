# https://neetcode.io/problems/time-based-key-value-store
# https://leetcode.com/problems/time-based-key-value-store/

from typing import List


class TimeMap:
    def __init__(self):
        self.hm = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.hm:
            self.hm[key].append((timestamp, value))
        else:
            self.hm[key] = [(timestamp, value)]

    def get(self, key: str, timestamp: int) -> str:
        temp = self.hm.get(key, [])
        ret = ""
        l, r = 0, len(temp) - 1
        while l <= r:
            m = l + (r - l) // 2
            if temp[m][0] <= timestamp:
                ret = temp[m][1]
                l = m + 1
            else:
                r = m - 1
        return ret

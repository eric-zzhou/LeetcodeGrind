# https://neetcode.io/problems/car-fleet
# https://leetcode.com/problems/car-fleet/

from typing import List


class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = list(zip(position, speed))
        cars.sort()

        ret = 1
        curr = cars.pop()
        dur = (target - curr[0]) / curr[1]
        while cars:
            curr = cars.pop()
            cdur = (target - curr[0]) / curr[1]
            if cdur > dur:
                ret += 1
                dur = cdur

        return ret

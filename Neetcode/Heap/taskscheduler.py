# https://neetcode.io/problems/task-scheduling
# https://leetcode.com/problems/task-scheduler/

from typing import List
from collections import Counter


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        track = Counter(tasks)

        arr = sorted(track.values(), reverse=True)

        add = n * (arr[0] - 1)
        for v in arr[1:]:
            add -= min(arr[0] - 1, v)
        return len(tasks) + max(add, 0)

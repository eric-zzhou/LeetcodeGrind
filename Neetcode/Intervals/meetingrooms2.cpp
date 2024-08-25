// https://neetcode.io/problems/meeting-schedule-ii
// https://leetcode.com/problems/meeting-rooms-ii

#include <algorithm>
#include <vector>
using namespace std;

class Interval {
 public:
  int start, end;
  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class Solution {
 public:
  int minMeetingRooms(vector<Interval>& intervals) {
    int ret = 0, curr = 0;
    vector<int> starts, ends;
    for (auto i : intervals) {
      starts.push_back(i.start);
      ends.push_back(i.end);
    }

    sort(starts.begin(), starts.end());
    sort(ends.begin(), ends.end());
    for (int i = 0, j = 0; i < starts.size(); i++) {
      if (starts[i] < ends[j]) {
        curr++;
      } else {
        j++;
      }
      ret = max(ret, curr);
    }
    return ret;
  }
};

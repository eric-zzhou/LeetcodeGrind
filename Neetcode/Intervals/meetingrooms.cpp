// https://neetcode.io/problems/meeting-schedule
// https://leetcode.com/problems/meeting-rooms

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
  bool canAttendMeetings(vector<Interval>& intervals) {
    sort(intervals.begin(), intervals.end(),
         [](Interval& a, Interval& b) { return a.start < b.start; });
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i - 1].end > intervals[i].start) {
        return false;
      }
    }
    return true;
  }
};

class Solution {
 public:
  bool canAttendMeetings(vector<Interval>& intervals) {
    int n = intervals.size();
    if (n <= 1) {
      return true;
    }
    sort(intervals.begin(), intervals.end(),
         [](Interval& a, Interval& b) { return a.start < b.start; });
    for (int i = 0; i < n - 1; i++) {
      if (intervals[i].end > intervals[i + 1].start) {
        return false;
      }
    }
    return true;
  }
};

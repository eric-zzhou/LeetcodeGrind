// https://neetcode.io/problems/insert-new-interval
// https://leetcode.com/problems/insert-interval

#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    int n = intervals.size(), i = 0;
    vector<vector<int>> ret;
    while (i < n && intervals[i][1] < newInterval[0]) {
      ret.push_back(intervals[i]);
      i++;
    }
    while (i < n && newInterval[1] >= intervals[i][0]) {
      newInterval[0] = min(newInterval[0], intervals[i][0]);
      newInterval[1] = max(newInterval[1], intervals[i][1]);
      i++;
    }
    ret.push_back(newInterval);
    while (i < n) {
      ret.push_back(intervals[i]);
      i++;
    }
    return ret;
  }
};

class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    int low = newInterval[0], high = newInterval[1];
    bool done = false;
    vector<vector<int>> ret;
    for (auto i : intervals) {
      if (i[1] < low) {
        ret.push_back(i);
      } else if (i[0] > high) {
        if (!done) {
          done = true;
          ret.push_back({low, high});
        }
        ret.push_back(i);
      } else {
        low = min(low, i[0]);
        high = max(high, i[1]);
      }
    }
    if (!done) {
      ret.push_back({low, high});
    }
    return ret;
  }
};
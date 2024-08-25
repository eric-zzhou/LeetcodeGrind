// https://neetcode.io/problems/non-overlapping-intervals
// https://leetcode.com/problems/non-overlapping-intervals

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Sort by end time
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(),
         [](vector<int>& a, vector<int>& b) { return a[1] < b[1]; });

    // ret tracks number of non-overlapping intervals
    int ret = 1;
    int time = intervals[0][1];

    // Count number of non-overlapping intervals
    for (int i = 1; i < n; i++) {
      if (intervals[i][0] >= time) {
        time = intervals[i][1];
        ret++;
      }
    }
    return n - ret;
  }
};

class Solution {
 public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    // for (auto v : intervals) {
    //     cout << "(" << v[0] << ", " << v[1] << ")" << " ";
    // }
    // cout << endl;

    int n = intervals.size();

    int ret = 0;
    int curr, cr;
    for (int i = 0; i < n; i++) {
      curr = 0;
      cr = intervals[i][1];
      while (i < n - 1 && cr > intervals[i + 1][0]) {
        i++;
        cr = min(cr, intervals[i][1]);
        ret++;
      }
    }
    return ret;
  }
};

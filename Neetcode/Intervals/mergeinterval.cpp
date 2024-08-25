// https://neetcode.io/problems/merge-intervals
// https://leetcode.com/problems/merge-intervals

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ret;
    for (int i = 0; i < intervals.size(); i++) {
      if (ret.empty() || intervals[i][0] > ret.back()[1]) {
        ret.push_back(intervals[i]);
      } else {
        ret.back()[1] = max(ret.back()[1], intervals[i][1]);
      }
    }
    return ret;
  }
};

class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    // for (auto v : intervals) {
    //     cout << "(" << v[0] << ", " << v[1] << ")" << " ";
    // }
    // cout << endl;

    vector<vector<int>> ret;
    int cl, cr;
    for (int i = 0; i < n; i++) {
      cl = intervals[i][0], cr = intervals[i][1];
      while (i < n - 1 && cr >= intervals[i + 1][0]) {
        i++;
        cr = max(cr, intervals[i][1]);
      }
      ret.push_back({cl, cr});
    }
    return ret;
  }
};

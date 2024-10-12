// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
// 10/12/2024

#include <standard.h>
using namespace std;

class Solution {
 public:
  int minGroups(vector<vector<int>>& intervals) {
    int ret = 0;
    vector<pair<int, bool>> all;
    for (auto v : intervals) {
      all.push_back({v[0], 0});
      all.push_back({v[1], 1});
    }
    sort(all.begin(), all.end());
    int curr = 0;
    for (auto [v, s] : all) {
      if (!s) {
        curr++;
        ret = max(ret, curr);
      } else {
        curr--;
      }
    }
    return ret;
  }
};
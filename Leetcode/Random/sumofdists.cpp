// https://leetcode.com/problems/sum-of-distances/

#include <standard.h>
using namespace std;

class Solution {
 public:
  vector<long long> distance(vector<int>& nums) {
    unordered_map<int, vector<int>> track;
    vector<long long> ret(nums.size());
    for (int i = 0; i < nums.size(); i++) {
      track[nums[i]].push_back(i);
    }
    int n;
    for (auto [k, v] : track) {
      n = v.size();
      vector<long long> pref(n + 1);
      pref[0] = 0;
      for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + v[i];
      }

      // n - i - 1 right side, i left side
      for (int i = 0; i < n; i++) {
        ret[v[i]] = ((long long)(i)*v[i] - pref[i] + pref[n] - pref[i + 1] -
                     (n - i - 1ll) * v[i]);
      }
    }
    return ret;
  }
};
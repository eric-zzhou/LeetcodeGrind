// https://leetcode.com/problems/longest-consecutive-sequence/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    if (nums.empty()) {
      return 0;
    }

    sort(nums.begin(), nums.end());
    int ret = 1, prev = nums[0], curr, track = 1;
    for (int i = 1; i < nums.size(); i++) {
      curr = nums[i];
      if (curr - prev == 1) {
        track++;
      } else if (curr == prev) {
        continue;
      } else {
        ret = max(ret, track);
        track = 1;
      }
      prev = curr;
    }
    return max(ret, track);
  }
};
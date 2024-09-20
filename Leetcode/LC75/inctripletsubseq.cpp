// https://leetcode.com/problems/increasing-triplet-subsequence/

#include <ios>
#include <vector>
using namespace std;

class Solution {
 public:
  bool increasingTriplet(vector<int>& nums) {
    ios::sync_with_stdio(false);
    int s1 = INT_MAX;
    int s2 = INT_MAX;
    for (auto num : nums) {
      if (num <= s1) {
        s1 = num;
      } else if (num <= s2) {
        s2 = num;
      } else {
        return true;
      }
    }
    return false;
  }
};
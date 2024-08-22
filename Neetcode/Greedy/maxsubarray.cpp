// https://neetcode.io/problems/maximum-subarray
// https://leetcode.com/problems/maximum-subarray

#include <iostream>
#include <vector>
using namespace std;

int speedUp = [] {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  return 0;
}();

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int ret = nums[0];
    int curr = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (curr < 0) {
        curr = 0;
      }
      curr += nums[i];
      ret = max(ret, curr);
    }
    return ret;
  }
};

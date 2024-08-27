// https://leetcode.com/problems/split-array-largest-sum/

#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
 public:
  int splitArray(vector<int>& nums, int k) {
    int ret;
    int r = reduce(nums.begin(), nums.end());
    int l = r / k - 1;
    while (l <= r) {
      int m = l + (r - l) / 2;
      // cout << m << endl;
      int curr = 0, count = 0;
      for (int i = 0; i < nums.size() && count < k; i++) {
        if (nums[i] > m) {
          count = k;
          break;
        }
        curr += nums[i];
        if (curr > m) {
          curr = nums[i];
          count++;
        }
      }
      if (count < k) {
        ret = m;
        r = m - 1;
      } else {
        l = m + 1;
      }
    }
    return ret;
  }
};
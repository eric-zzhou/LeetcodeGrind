// https://leetcode.com/problems/max-number-of-k-sum-pairs/

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxOperations(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int l = 0, r = nums.size() - 1, ret = 0;
    while (l < r) {
      if (nums[l] + nums[r] < k) {
        l++;
      } else if (nums[l] + nums[r] > k) {
        r--;
      } else {
        ret++;
        l++;
        r--;
      }
    }
    return ret;
  }
};
#include <vector>
using namespace std;

class Solution {
 public:
  int helper(vector<int>& nums, int s, int e) {
    int temp, r1 = 0, r2 = 0;
    for (int i = s; i < e; ++i) {
      temp = max(r1 + nums[i], r2);
      r1 = r2;
      r2 = temp;
    }
    return r2;
  }

  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }
    return max(helper(nums, 0, n - 1), helper(nums, 1, n));
  }
};
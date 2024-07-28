#include <vector>
using namespace std;

// Space efficient solution
class Solution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    int first = nums[0], second = max(first, nums[1]);
    for (int i = 2; i < n; i++) {
      int t = second;
      second = max(second, nums[i] + first);
      first = t;
    }
    return second;
  }
};

class LargerSolution {
 public:
  int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) {
      return nums[0];
    }

    nums[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; ++i) {
      nums[i] = max(nums[i - 1], nums[i - 2] + nums[i]);
    }
    return nums[n - 1];
  }
};

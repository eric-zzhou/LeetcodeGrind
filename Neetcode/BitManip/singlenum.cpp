// https://neetcode.io/problems/single-number
// https://leetcode.com/problems/single-number/

#include <vector>
using namespace std;

class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      ret ^= nums[i];
    }
    return ret;
  }
};

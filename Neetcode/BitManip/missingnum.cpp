// https://neetcode.io/problems/missing-number
// https://leetcode.com/problems/missing-number/

#include <vector>
using namespace std;

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      ret ^= i ^ nums[i];
    }
    return ret ^ nums.size();
  }
};

class Solution {
 public:
  int missingNumber(vector<int>& nums) {
    int n = nums.size();
    int sum = n * (n + 1) / 2;
    for (int i = 0; i < n; i++) {
      sum -= nums[i];
    }
    return sum;
  }
};
// https://neetcode.io/problems/jump-game
// https://leetcode.com/problems/jump-game

#include <vector>
using namespace std;

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int n = nums.size();
    int currm = nums[0];
    int i;
    for (i = 1; i < n && currm > 0; i++) {
      currm--;
      currm = max(currm, nums[i]);
    }
    return (i == n) ? true : false;
  }
};

class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int goal = nums.size() - 1;

    for (int i = nums.size() - 2; i >= 0; i--) {
      if (i + nums[i] >= goal) {
        goal = i;
      }
    }

    return goal == 0;
  }
};
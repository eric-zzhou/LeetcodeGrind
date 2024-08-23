// https://neetcode.io/problems/jump-game-ii
// https://leetcode.com/problems/jump-game-ii

#include <queue>
#include <vector>
using namespace std;

// Better variable names
class Solution {
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    int ret = 0, l = 0, r = 0;

    while (r < n - 1) {
      ret++;
      int furthest = 0;
      for (int i = l; i <= r; i++) {
        furthest = max(furthest, i + nums[i]);
      }
      l = r + 1;
      r = furthest;
    }
    return ret;
  }
};

class Solution {
 public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    int ret = 0, ind = 0;
    int furthest = 0;

    while (furthest < n - 1) {
      ret++;
      int temp = 0;
      for (int i = ind; i <= furthest; i++) {
        temp = max(temp, i + nums[i]);
      }
      ind = furthest + 1;
      furthest = temp;
      // cout << ind << ", " << furthest << endl;
    }
    return ret;
  }
};

// https://neetcode.io/problems/burst-balloons
// https://leetcode.com/problems/burst-balloons

#include <vector>
using namespace std;

class Solution {
 public:
  int maxCoins(vector<int>& nums) {
    // Add [1] to the beginning and end of the array
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    int n = nums.size();

    // dp[l][r] = max coins obtained by bursting balloons from l to r
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int r, mult;

    // off is the distance between l and r, we loop through all possible lengths
    //  of subarrays in nums, this allows us to do tabloid dp
    for (int off = 1; off <= n - 2; off++) {
      for (int l = 1; l < n - off; l++) {
        r = l + off - 1;
        mult = nums[l - 1] * nums[r + 1];
        for (int i = l; i <= r; i++) {
          dp[l][r] =
              max(dp[l][r], dp[l][i - 1] + nums[i] * mult + dp[i + 1][r]);
        }
      }
    }

    // Ans is the maximum coins obtained by bursting balloons from 1 to n - 2,
    //  ignoring added 1s
    return dp[1][n - 2];
  }
};

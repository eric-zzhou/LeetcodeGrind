// https://neetcode.io/problems/target-sum
// https://leetcode.com/problems/target-sum/

#include <numeric>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    // Get total and new target which is half of the difference
    int n = nums.size();
    int total = accumulate(nums.begin(), nums.end(), 0);

    /* Problem is basically asking to find all possible subsets splits with
     positive and negative signs and we want sum(P) - sum(N) = target and
     we have sum(P) + sum(N) = total. Combining these gives 2 * sum(P) =
     total + target which becomes 2 * (sum(P) - target) = total - target which
     has to be even. Therefore, we also just need to get new
     target of (total - target) / 2 to find all possible subsets since total -
     target = sum(P) + sum(N) - sum(P) + sum(N) = 2 * sum(N). Now problem
     statement is just find all subsets that sum to (total - target) / 2 */
    int ntarget = (total - target) / 2;

    // Check if target is possible (reacheable and even difference)
    if (total - target < 0 || (total - target) % 2) return 0;

    // Since ntarget isolates positives, we don't have to consider neg case
    vector<vector<int>> dp(n, vector<int>(ntarget + 1, 0));
    // Base cases to handle first number
    if (nums[0] <= ntarget) dp[0][nums[0]] = 1;
    if (nums[0] == 0)
      dp[0][0] = 2;
    else
      dp[0][0] = 1;

    // Iterate through nums
    for (int i = 1; i < n; i++) {
      // Iterate through each number up to target
      for (int j = 0; j <= ntarget; j++) {
        // Number of ways to get to j taking ith number
        int take = 0;
        // Standard dp check
        if (j >= nums[i]) take = dp[i - 1][j - nums[i]];
        // Number of ways to get to j without taking ith number
        int notTake = dp[i - 1][j];
        dp[i][j] = take + notTake;
      }
    }
    // Return number of ways to achieve ntarget with all subsets considered
    return dp[n - 1][ntarget];
  }
};

class MemoSolution {
 public:
  unordered_map<long, int> mem;
  int findTargetSumWays(vector<int>& nums, int target) {
    return dp(nums, target, nums.size() - 1, 0);
  }

  int dp(vector<int>& nums, int target, int index, int currsum) {
    long key = currsum * 100 + index;
    if (mem.find(key) != mem.end()) {
      return mem[key];
    }
    if (index < 0 && currsum == target) {
      return 1;
    }
    if (index < 0) {
      return 0;
    }

    mem[key] = dp(nums, target, index - 1, currsum - nums[index]) +
               dp(nums, target, index - 1, currsum + nums[index]);
    return mem[key];
  }
};

class StupidSolutionByMe {
 public:
  int findTargetSumWays(vector<int>& nums, int target) {
    unordered_map<int, int> track;
    track[0] = 1;
    for (int n : nums) {
      unordered_map<int, int> temp;
      for (auto v : track) {
        temp[v.first + n] += v.second;
        temp[v.first - n] += v.second;
      }
      track = temp;
      // for (auto v : track) {
      //     cout << "(" << v.first << ", " << v.second << ") ";
      // }
      // cout << endl;
    }
    return track[target];
  }
};
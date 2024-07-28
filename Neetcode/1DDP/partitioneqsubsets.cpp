#include <bitset>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  // I/O optimization
  int init = [] {
    ios_base::sync_with_stdio(false);
    return 0;
  }();

  bool canPartition(vector<int>& nums) {
    // Check if sum is odd
    int sum = 0;
    for (int i : nums) sum += i;
    if (sum & 1) return false;

    // Create bitset for all possible numbers with 0 as 1
    bitset<200 / 2 * 100 + 1> dp(0);
    dp[0] = 1;

    // Iterate through nums
    for (int i : nums) {
      dp |= dp << i;  // Gets all possible sums of numbers using shift
      if (dp[sum / 2]) return true;  // Check if target is possible
    }
    return dp[sum / 2];
  }
};

class BadSolution {
 public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int n : nums) {
      sum += n;
    }
    if (sum % 2 == 1) {
      return false;
    }

    sum /= 2;
    unordered_set<int> track;
    track.insert(0);
    for (int n : nums) {
      unordered_set<int> temp;
      for (int v : track) {
        if (n + v == sum) {
          return true;
        } else if (n + v < sum) {
          temp.insert(n + v);
        }
        temp.insert(v);
      }
      track = temp;
    }
    return false;
  }
};

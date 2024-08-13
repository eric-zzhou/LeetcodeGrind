// https://leetcode.com/problems/count-number-of-nice-subarrays/

#include <iostream>
#include <vector>
using namespace std;

// IO optimization
static const bool Booster = []() {
  ios_base::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  return true;
}();

// Prefix sum solution
class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int n = nums.size();

    // Count the number of odd numbers in the prefix of nums
    vector<int> cnt(n + 1, 0);
    cnt[0] = 1;
    int ans = 0, t = 0;

    for (int v : nums) {
      // If v is odd, increment t
      t += v & 1;
      // If more odds than k, increase answer by count of t - k odds (finds the
      //  number of subarrays at start that you can remove to get back to k)
      if (t - k >= 0) {
        ans += cnt[t - k];
      }

      // Increment count of t
      cnt[t]++;
    }
    return ans;
  }
};

class MyGoodSolution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    vector<int> odds;
    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] % 2 == 1) {
        odds.push_back(i);
      }
    }

    if (odds.size() < k) return 0;
    int ret = 0;
    for (int r = k - 1; r < odds.size(); r++) {
      // l = r - k + 1
      // cout << r << ", " << k << ", " << odds[r-k+1] << ", " << odds[r] <<
      // endl;
      int left =
          (r >= k) ? (odds[r - k + 1] - odds[r - k]) : odds[r - k + 1] + 1;
      // cout << "left: " << left << endl;
      int right = (r < odds.size() - 1) ? (odds[r + 1] - odds[r])
                                        : (nums.size() - odds[r]);
      // cout << "right: " << right << endl;
      ret += left * right;
    }
    return ret;
  }
};
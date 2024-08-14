// https://leetcode.com/problems/k-diff-pairs-in-an-array/

#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

// Naive O(N) solution
class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    if (k == 0) {
      unordered_map<int, int> track;
      int ret = 0;
      for (int v : nums) {
        if (track.find(v) != track.end()) {
          if (track[v] == 1) {
            ret++;
          }
          track[v]++;
        } else {
          track[v] = 1;
        }
      }
      return ret;
    }
    unordered_set<int> track(nums.begin(), nums.end());
    int ret = 0;
    for (auto v : track) {
      if (track.find(v - k) != track.end()) {
        ret += 1;
      }
    }
    return ret;
  }
};

// Interesting sliding window O(N log N) solution
class Solution {
 public:
  int findPairs(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    set<pair<int, int>> ans;

    int i = 0, j = 1;
    while (j < nums.size()) {
      int diff = nums[j] - nums[i];
      if (diff == k) {
        ans.insert({nums[i], nums[j]});
        ++i;
        ++j;
      } else if (diff > k) {
        i++;
      } else {
        j++;
      }
      if (i == j) {
        j++;
      }
    }
    return ans.size();
  }
};
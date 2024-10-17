// https://leetcode.com/problems/subarray-sum-equals-k/

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int subarraySum(vector<int>& nums, int k) {
    // Track number of occurrences for all past values
    unordered_map<int, int> track;
    int sum = 0, ret = 0;
    track[sum] = 1;

    for (auto v : nums) {
      // Current sum
      sum += v;

      // Target is sum - k, find all prefix arrays that are equal to sum - k
      int t = sum - k;
      if (track.find(t) != track.end()) {
        ret += track[t];
      }

      // Increase count of sum, aka prefix arrays with this sum
      track[sum]++;
    }
    return ret;
  }
};
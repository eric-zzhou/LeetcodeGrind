// https://neetcode.io/problems/merge-triplets-to-form-target
// https://leetcode.com/problems/merge-triplets-to-form-target-triplet/

#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    bool x = false, y = false, z = false;
    for (auto v : triplets) {
      if (v[0] <= target[0] && v[1] <= target[1] && v[2] <= target[2]) {
        x = x || v[0] == target[0];
        y = y || v[1] == target[1];
        z = z || v[2] == target[2];
      }
      if (x && y && z) {
        return true;
      }
    }
    return false;
  }
};

class OriginalSolution {
 public:
  bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
    vector<int> track(3, 0);
    for (auto v : triplets) {
      if (v[0] <= target[0] && v[1] <= target[1] && v[2] <= target[2]) {
        track[0] = max(track[0], v[0]);
        track[1] = max(track[1], v[1]);
        track[2] = max(track[2], v[2]);
      }
    }
    return track == target;
  }
};
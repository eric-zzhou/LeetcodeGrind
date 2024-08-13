// https://leetcode.com/problems/3sum-with-multiplicity/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int threeSumMulti(vector<int>& arr, int target) {
    unordered_map<int, long> track;
    for (int v : arr) track[v]++;

    long ret = 0;
    for (auto v : track) {
      for (auto v2 : track) {
        int i = v.first, j = v2.first, k = target - i - j;
        if (track.find(k) == track.end()) continue;
        if (i == j && j == k) {
          ret += track[i] * (track[i] - 1) * (track[i] - 2) / 6;
        } else if (i == j && j != k) {
          ret += track[i] * (track[i] - 1) / 2 * track[k];
        } else if (i < j && j < k) {
          ret += track[i] * track[j] * track[k];
        }
      }
    }
    return ret % int(1e9 + 7);
  }
};
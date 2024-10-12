// https://leetcode.com/problems/rank-transform-of-an-array
// 10/02/2024

#include <standard.h>
using namespace std;

class Solution {
 public:
  vector<int> arrayRankTransform(vector<int>& arr) {
    set<int> myset(arr.begin(), arr.end());
    unordered_map<int, int> ranks;
    int ind = 1;
    for (auto a : myset) {
      ranks[a] = ind++;
    }

    for (int i = 0; i < arr.size(); i++) {
      arr[i] = ranks[arr[i]];
    }
    return arr;
  }
};
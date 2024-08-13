// https://leetcode.com/problems/array-of-doubled-pairs/

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

static int io_opt = []() {
  ios::sync_with_stdio(false);
  return 0;
}();

class cmp {
 public:
  bool operator()(int a, int b) {
    if (abs(a) == abs(b)) {
      return a < b;
    } else {
      return abs(a) < abs(b);
    }
  }
};
class Solution {
 public:
  bool canReorderDoubled(vector<int>& arr) {
    // Count the occurrences of each number
    unordered_map<int, int> track;
    for (int a : arr) {
      ++track[a];
    }

    // Sort the keys in increasing abs order
    vector<int> keys;
    for (auto v : track) {
      keys.push_back(v.first);
    }
    sort(keys.begin(), keys.end(), cmp());

    // Iterate through the keys and check if the count of each number is valid
    size_t half = arr.size() / 2, counted = 0;
    for (int k : keys) {
      if (track[k] == 0) {
        continue;
      }
      if (track[k] > track[k * 2]) {
        return false;
      } else {
        track[k * 2] -= track[k];
        counted += track[k];
      }

      // Stop early
      if (counted == half) {
        return true;
      }
    }
    return true;
  }
};

class MySolution {
 public:
  bool canReorderDoubled(vector<int>& arr) {
    // Sort the array by absolute values
    sort(arr.begin(), arr.end(), [](int a, int b) { return abs(a) < abs(b); });

    // Use an unordered_map to track occurrences of each number
    unordered_map<int, int> track;
    for (int v : arr) {
      track[v]++;
    }

    for (int v : arr) {
      if (track[v] == 0)
        continue;  // Skip if the current number is already used
      int twice = v * 2;
      if (track[twice] == 0) {
        return false;  // If there is no matching doubled value
      }
      // Decrease the count for the current number and its double
      track[v]--;
      track[twice]--;
    }
    return true;
  }
};

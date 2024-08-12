// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int numPairsDivisibleBy60(vector<int>& time) {
    vector<int> count(60, 0);
    for (int t : time) {
      count[t % 60]++;
    }
    long long ans = (1ll * count[0] * (count[0] - 1)) / 2 +
                    (1ll * count[30] * (count[30] - 1)) / 2;
    for (int i = 1; i <= 29; i++) {
      ans += 1ll * count[i] * count[60 - i];
    }
    return int(ans);
  }
};

class Solution {
 public:
  int numPairsDivisibleBy60(vector<int>& time) {
    unordered_map<int, long> track;
    for (int t : time) {
      track[t % 60]++;
    }

    long ret = 0;
    for (auto v : track) {
      if (v.first > 30) {
        continue;
      }
      if (v.first == 30 || v.first == 0) {
        ret += v.second * (v.second - 1) / 2;
      } else {
        if (track.find(60 - v.first) != track.end()) {
          ret += v.second * track[60 - v.first];
        }
      }
    }
    return (int)ret;
  }
};
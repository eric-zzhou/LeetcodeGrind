// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestPalindrome(vector<string>& words) {
    unordered_map<string, int> track;
    for (string word : words) {
      track[word]++;
    }

    int ret = 0;
    bool mid = false;
    for (auto v : track) {
      char first = v.first.at(0);
      char second = v.first.at(1);
      if (first < second) {
        string reversed = {second, first};
        if (track.find(reversed) != track.end()) {
          ret += 4 * min(v.second, track[reversed]);
        }
      } else if (first == second) {
        ret += (v.second / 2) * 4;
        mid = mid || v.second % 2;
      }
    }
    if (mid) ret += 2;
    return ret;
  }
};
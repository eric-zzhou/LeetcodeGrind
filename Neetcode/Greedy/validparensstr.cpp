// https://neetcode.io/problems/valid-parenthesis-string
// https://leetcode.com/problems/valid-parenthesis-string

#include <string>
using namespace std;

class Solution {
 public:
  bool checkValidString(string s) {
    int free = 0, track = 0;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '*') {
        free++;
      } else if (s[i] == '(') {
        track++;
      } else {
        track--;
      }
      if (track < 0) {
        if (free == 0) {
          return false;
        }
        free--;
      }
    }
    return track - free <= 0;
  }
};
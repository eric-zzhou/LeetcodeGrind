// https://neetcode.io/problems/valid-parenthesis-string
// https://leetcode.com/problems/valid-parenthesis-string

#include <string>
using namespace std;

class Solution {
 public:
  bool checkValidString(string s) {
    // lmin tracks least number of left brackets, lmax tracks most number of
    //  left brackets
    int lmin = 0, lmax = 0;
    for (char c : s) {
      if (c == '(') {
        lmin++;
        lmax++;
      } else if (c == ')') {
        lmin--;
        lmax--;
      }
      // wildcard can be either left or right bracket
      else {
        lmin--;
        lmax++;
      }

      // more right brackets than left occurred, meaning invalid
      if (lmax < 0) {
        return false;
      }
      // lmin can't be negative
      lmin = max(lmin, 0);
    }
    // lmin == 0 means all left brackets can be matched
    return lmin == 0;
  }
};

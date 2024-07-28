#include <string>
using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    int n = s.size();
    int mlen = 0;
    string ret = "";

    int l, r;
    for (int i = 0; i < n; i++) {
      l = i;
      r = i;
      while (l >= 0 && r < n && (s.at(l) == s.at(r))) {
        l--;
        r++;
      }
      if (r - l - 1 > mlen) {
        mlen = r - l - 1;
        ret = s.substr(l + 1, mlen);
      }

      l = i;
      r = i + 1;
      while (l >= 0 && r < n && (s.at(l) == s.at(r))) {
        l--;
        r++;
      }
      if (r - l - 1 > mlen) {
        mlen = r - l - 1;
        ret = s.substr(l + 1, mlen);
      }
    }
    return ret;
  }
};

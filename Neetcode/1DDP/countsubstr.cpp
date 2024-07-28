#include <string>
using namespace std;

class Solution {
 public:
  int countSubstrings(string s) {
    int n = s.size();
    int ret = 0;

    int l, r;
    for (int i = 0; i < n; i++) {
      l = i;
      r = i;
      while (l >= 0 && r < n && (s.at(l) == s.at(r))) {
        l--;
        r++;
        ret++;
      }

      l = i;
      r = i + 1;
      while (l >= 0 && r < n && (s.at(l) == s.at(r))) {
        l--;
        r++;
        ret++;
      }
    }
    return ret;
  }
};

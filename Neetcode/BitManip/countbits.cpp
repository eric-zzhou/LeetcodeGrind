// https://neetcode.io/problems/counting-bits
// https://leetcode.com/problems/counting-bits/

#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> ret(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      (i & 1) ? ret[i] = ret[i - 1] + 1 : ret[i] = ret[i >> 1];
    }
    return ret;
  }
};

class Solution {
 public:
  vector<int> countBits(int n) {
    vector<int> ret(n + 1, 0);
    for (int i = 1; i <= n; i++) {
      ret[i] = ret[i & (i - 1)] + 1;
    }
    return ret;
  }
};

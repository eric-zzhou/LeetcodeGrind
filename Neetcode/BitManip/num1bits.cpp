// https://neetcode.io/problems/number-of-one-bits
// https://leetcode.com/problems/number-of-1-bits/

#include <cstdint>
using namespace std;

class Solution {
 public:
  int hammingWeight(uint32_t n) {
    int ret = 0;
    while (n) {
      ret += n & 1;
      n >>= 1;
    }
    return ret;
  }
};

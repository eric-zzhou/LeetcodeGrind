// https://neetcode.io/problems/reverse-bits
// https://leetcode.com/problems/reverse-bits/

#include <cstdint>
using namespace std;

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; ++i) {
      result <<= 1;
      result |= (n & 1);
      n >>= 1;
    }
    return result;
  }
};

class Solution {
 public:
  uint32_t reverseBits(uint32_t n) {
    for (int i = 0; i < 16; i++) {
      if (((n >> i) & 1) != (n >> (31 - i) & 1)) {
        n ^= 1 << i;
        n ^= 1 << (31 - i);
      }
    }
    return n;
  }
};

class MySolution {
 public:
  uint32_t reverseBits(uint32_t n) {
    for (int i = 0; i < 16; i++) {
      if (((n >> i) & 1) && (n & (1 << (31 - i))) == 0) {
        n ^= 1 << i;
        n |= 1 << (31 - i);
      } else if (((n >> i) & 1) == 0 && (n & (1 << (31 - i)))) {
        n |= 1 << i;
        n ^= 1 << (31 - i);
      }
    }
    return n;
  }
};